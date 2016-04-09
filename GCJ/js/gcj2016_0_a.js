#!/usr/bin/env node
"use strict";

var Utils = require('./gcjUtils');

const LOG = require('bunyan').createLogger({name:'prob a', level:'debug'});

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

Utils.solveAll(new Utils.TReader(process.argv[2]), solveCase, new Utils.TWriter(process.argv[3])).done();
