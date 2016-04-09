#!/usr/bin/env node
"use strict";

var FS   = require('fs'),
    Q    = require('q'),
    Path = require('path'),
    LOG  = require('bunyan').createLogger({name : "gcj"}),
    _    = require('lodash');

const EPSILON = 1e-6;

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

const TReader = function () {
  const dataLines = FS.readFileSync(process.argv[2], {encoding : 'UTF8'}).split('\n');

  this.numberOfCases = () => Number(dataLines[0]);

  this.getCaseIterator = () => makeArrayIterator(dataLines.slice(1));

  this.getCase = caseNum => dataLines[caseNum];
};

const TWriter = function (caseNum, solution) {
  this.solutions = {};
  this.add = (caseNum, solution) => this.solutions[caseNum] = solution;
  this.flush = () => Q(FS.writeFileSync(process.argv[3], _.map(_.keys(this.solutions), caseNum => `Case #${caseNum}: ${this.solutions[caseNum]}`).join('\n')));
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
    writer.flush().then(() => promise.resolve(Date.now() - startTime));
  } catch (error) {
    promise.reject(error);
  }
  return promise.promise;
};

const solveCase = input => {
  const N = Number.parseInt(input);
  LOG.info(`Solving for ${N}`);
  
  if (N === 0) return 'INSOMNIA';
  const seen = {};
  var counter = 0;
  let ret = 1;
  while (true) {
    var Ni = N * ret;
    LOG.info(seen, `Ni ${Ni}, counter ${counter}`);
    while (Ni >= 1) {
      var NiMod = Number.parseInt(Ni%10);
      if (!seen[NiMod]) {
        seen[NiMod] = true;
        counter++;
        if (counter === 10) {
          return N * ret;
        }
      }
      Ni = Ni / 10;
    }
    ret += 1;
  }
  return "fuck";
};

solveAll(new TReader(), solveCase, new TWriter()).then(
  ms => LOG.info(`Solved in ${ms/1000.0} seconds`), error => {
    LOG.error(error);
  });
