#!/usr/local/bin/python

# Facebook programming puzzle
# Peak Traffic
#
# URL: http://tungwaiyip.info/blog/2010/03/03/peak_traffic_solution_facebook_programming_puzzle

import itertools
import math
from pprint import pprint as pp
import sys
import time

# Map name -> id, where id in 1..n
users       = {}

# id -> name
id2name     = [None]

# id -> (set of receiver, set of sender)
user_log    = [(set(),set())]

edges = []

#
clique_by_v = {}


def log(msg):
    print >>sys.stderr, '>>', msg


def str_set_of_id(s):
    return '[%s]' % (','.join(map(str,sorted(s))))


def flatten(listOfLists):
    return list(itertools.chain(*listOfLists))


def lookup_or_add(name):
    id = users.get(name, None)
    if not id:
        id = len(id2name)
        users[name] = id
        id2name.append(name)
        # for id, add (set of receiver, set of sender)
        user_log.append((set(),set()))
    return id


def load(filename):
    """ Load file into users and user_log """
    fp = open(filename)
    try:
        for line in fp:
            line = line.strip()
            ts,u1,u2 = line.split('\t')

            id1 = lookup_or_add(u1)
            id2 = lookup_or_add(u2)

            # id1 sent to id2
            user_log[id1][0].add(id2)

            # id2 receive from id1
            user_log[id2][1].add(id1)

    finally:
        fp.close()


def make_bidirect_graph(user_log):
    edges = []
    for id, (to_set, from_set) in enumerate(user_log):
        bidirect = to_set & from_set
        #bidirect_low2high = sorted(id2 for id2 in bidirect if id2 > id)
        bidirect_low2high = sorted(id2 for id2 in bidirect if id2 > id)
        # note: if bidirect_low2high is empty, it can either because it does not
        # have bidirectional edge, or all bidirectional edges goes to lower
        # nodes. Theoretically we can dump the node if there are no
        # bidirectional edges. But we rather not to renumber the nodes. So we
        # will keep an empty set here.
        edges.append(bidirect_low2high)
    return edges

class V_clique:

    def __init__(self, v, clique):
        self.v = v
        self.clique_list = map(set, clique)
        self.V2 = reduce(set.union, self.clique_list, set())

    def __repr__(self):
        cliques = ', '.join(str_set_of_id(c)
            for c in self.clique_list)
        return '%s -> %s' % (self.v, cliques)

rec_counter = 0

def find_all_cliques(E, v_last, rec = 0):
    """
    Find all cliques in graph E.

    E: is a map of i -> V, where
        i is the node id
        V is a set of node i connected to (with higher id)
    V_last: The last vertex that invoke this recusively or None.

    @returns:
        list of cliques,
        where a clique is a list of vertex ids.
    """
#    log('find_all_cliques E=%s'%E)


    found_cliques = []
    global rec_counter
    rec_counter = max(rec_counter,rec)
    for from_id, V in E.items():

        if len(V) == 1:
            # Base case, from_id and V[0] form a 2 node clique
            if v_last:
                c = [from_id,iter(V).next()]
                found_cliques.append(c)
            # note: if this is top level, don't append because it has no chance to form a 3 node clique

        elif len(V) > 1:

            # first add all 2 node cliques
            if v_last:
                found_cliques.extend([from_id, v] for v in V)

            # find a subgraph of E where all vertex are in V
            subgraph = dict(
                (j,  filter(lambda v2: v2 in V, E[j]))
                for j in V)

            # use recursion to find all sub-clique
            sub_cliques = find_all_cliques(subgraph, from_id, rec + 1)

            for c in sub_cliques:
                c.insert(0,from_id)

            found_cliques.extend(sub_cliques)

            # if this is first level recursive call, update the clique_by_v map
            if not v_last:
                v_clique = V_clique(from_id, sub_cliques)
                clique_by_v[from_id] = v_clique

#    log('return %s cliques=%s' % (V_last, found_cliques))
    return found_cliques



def filter_subgraph():
    # map of V -> list
    # where V is a vertex
    # and list is list of clique where V is its first member


#    pp(clique_by_v)
    for v1_clique in clique_by_v.values():
        V2 = v1_clique.V2
        for v2 in V2:
            v2_clique = clique_by_v.get(v2,None)

            if not v2_clique or (not v2_clique.clique_list):
                continue

            v1_v2_cliques = [c for c in v1_clique.clique_list if v2 in c]

            # filter out items in v2_clique that is a subset of item in v1_v2_cliques
            # put the filtered result in new_list
            new_list = []
            for c2 in v2_clique.clique_list:
                if not (c2 <= V2):
                    new_list.append(c2)
                elif not any(c2 <= c1 for c1 in v1_v2_cliques if c2 is not c1):
                    new_list.append(c2)
                else:
#                    log('Drop %s < %s' % (str_set_of_id(c2),v1_clique.v))
                    pass

            if len(new_list) < len(v2_clique.clique_list):
                v2_clique.clique_list = new_list
                # is this worth to recalc?
                v2_clique.V2 = reduce(set.union,new_list,set())



start_time = time.time()

def elapsed():
    return time.time() - start_time

def output(all_cliques):
    out = []
    for c in all_cliques:
        names = [id2name[id] for id in c]
        out.append(', '.join(sorted(names)))

    for s in sorted(out):
        print s


def main(filename):

    load(filename)

    log('%2.1f Loaded' % elapsed())

    global edges
    global rec_counter
    edges = make_bidirect_graph(user_log)

    #pp(edges,sys.stderr)

    E = dict(enumerate(edges))
    cliques = find_all_cliques(E, None)

    log('%2.1f find_all_cliques: %s' % (elapsed(), len(cliques)))

#    pp(cliques)
#    pp(clique_by_v)

    filter_subgraph()

    all_cliques = flatten(vc.clique_list for vc in clique_by_v.values())

    log('%2.1f filter_subgraph: %s' % (elapsed(), len(all_cliques)))

    output(all_cliques)

#    pp(all_cliques )
    log('%2.1f count: %s' % (elapsed(), len(all_cliques)))

    log( 'Rec counter = %s' % rec_counter )


if __name__ =='__main__':
    filename = sys.argv[1]
    main(filename)
