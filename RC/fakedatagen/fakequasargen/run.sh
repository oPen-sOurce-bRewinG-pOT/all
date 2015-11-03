#!/bin/bash
mkdir data/sdss
mkdir data/sdss/bbsplf

time ./generator 4 data/sdss/bbsplf1.dat 15 1 sdss 30 7 10 8
time ./generator 4 data/sdss/bbsplf2.dat 15 2 sdss 30 7 10 8
time ./generator 4 data/sdss/bbfpls1.dat 15 1 sdss 15 5 30 7
time ./generator 4 data/sdss/bbfpls2.dat 15 2 sdss 15 5 30 7
time ./generator 4 data/sdss/bbfplf1.dat 15 1 sdss 15 5 6 4
time ./generator 4 data/sdss/bbfplf2.dat 15 2 sdss 15 5 6 4
time ./generator 4 data/sdss/bbspls1.dat 15 1 sdss 30 7 28 10
time ./generator 4 data/sdss/bbspls2.dat 15 2 sdss 30 7 28 10
