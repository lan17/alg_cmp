#!/bin/bash

i=10
while [ $i -gt 0 ]; do
	echo $i
	java GatTest 100000 100000 $i > 10k_$i.in
	java GatTest 1000000 1000000 $i > 1m_$i.in
	let i=i-1
	done
