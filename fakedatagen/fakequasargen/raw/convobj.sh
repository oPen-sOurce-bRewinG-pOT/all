#!/bin/bash

mkdir bbfplf
mkdir bbfpls
mkdir bbspls
mkdir bbsplf

mkdir bbfplf/t2
mkdir bbfpls/t2
mkdir bbspls/t2
mkdir bbsplf/t2

mkdir bbfplf/t1
mkdir bbfpls/t1
mkdir bbspls/t1
mkdir bbsplf/t1

python objconvert.py bbfplf1.dat bbfplf/t 1
python objconvert.py bbfplf2.dat bbfplf/t 2

python objconvert.py bbfpls1.dat bbfpls/t 1
python objconvert.py bbfpls2.dat bbfpls/t 2

python objconvert.py bbspls1.dat bbspls/t 1
python objconvert.py bbspls2.dat bbspls/t 2

python objconvert.py bbsplf1.dat bbsplf/t 1
python objconvert.py bbsplf2.dat bbsplf/t 2
