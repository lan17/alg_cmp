"use strict";

var FS = require('fs'),
    _ = require('lodash'),
    Q = require('q'),
    Path = require('path');

const LOG = require('bunyan').createLogger({name: 'utils', level:'debug'});

const makeArrayIterator = array => {
    var index = 0;

    return {
        next(){
            return array[index++];
        },
        hasNext(){
            index < array.length;
        }
    };
};

const TReader = function(inputFile) {
    const dataLines = FS.readFileSync(Path.resolve(inputFile), {encoding : 'UTF8'}).split('\n');

    this.numberOfCases = () => Number(dataLines[0]);
    this.getCaseIterator = () => makeArrayIterator(dataLines.slice(1));
    this.getCase = caseNum => dataLines[caseNum];
};

const TWriter = function(outputFile) {
    this.solutions = {};
    this.add = (caseNum, solution) => this.solutions[caseNum] = solution;
    this.flush = () => Q(FS.writeFileSync(Path.resolve(outputFile), 
        _.map(_.keys(this.solutions), 
            caseNum => `Case #${caseNum}: ${this.solutions[caseNum]}`).join('\n')));
};

const solveAll = (reader, solver, writer) => {
    const startTime = Date.now();
    const T = reader.numberOfCases()
    const promise = Q.defer();
    var semaphore = T;
    try {
        for (var i = 0; i < T; i += 1) {
            const ii = i;
            var solution = solver(reader.getCase(i + 1));
            writer.add(i + 1, solution);
        }
        writer.flush()
            .then(() => (Date.now() - startTime)/1000.0)
            .then(seconds => LOG.info(`Solving ${T} cases took ${seconds} seconds.`))
            .then(promise.resolve())
            .done();
    } catch (error) {
        promise.reject(error);
    }
    return promise.promise;
};

module.exports = {
    EPSILON: 1e-6,
    TReader: TReader,
    TWriter: TWriter,
    solveAll: solveAll
};
