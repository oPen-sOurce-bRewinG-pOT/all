#!/bin/bash
python histogram_binning.py 100_0.8.dat 100_0.8out.dat
python normalizer_2coldat.py 100_0.8out.dat 100_0.8out_n.dat
python histogram_binning.py 100_0.0.dat 100_0.0out.dat
python normalizer_2coldat.py 100_0.0out.dat 100_0.0out_n.dat
python histogram_binning.py 100_0.4.dat 100_0.4out.dat
python normalizer_2coldat.py 100_0.dat.4out 100_0.4out_n.dat
python histogram_binning.py 100_0.6.dat 100_0.6out.dat
python normalizer_2coldat.py 100_0.6out.dat 100_0.6out_n.dat
python histogram_binning.py 100_0.2.dat 100_0.2out.dat
python normalizer_2coldat.py 100_0.2out.dat 100_0.2out_n.dat
