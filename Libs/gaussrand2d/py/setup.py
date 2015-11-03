from setuptools import setup #, Extension
import os, os.path
import re

longDescription= ""


setup(name='gauss_rand_2d',
      version='1.0a0',
      description='2D Random Field Generator',
      author='Sunip Mukherjee',
      author_email='sunipkmukherjee@gmail.com',
      license='New BSD',
      long_description=longDescription,
      package_dir = {'gauss_rand_2d/': ''},
      packages=['gauss_rand_2d'],
      install_requires=['numpy']
      )
