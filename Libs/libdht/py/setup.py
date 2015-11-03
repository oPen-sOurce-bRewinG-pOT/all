from setuptools import setup #, Extension
import os, os.path
import re

longDescription= ""


setup(name='d_hankel_t',
      version='1.0a0',
      description='1D Hankel Transform Library requires GSL',
      author='Sunip Mukherjee',
      author_email='sunipkmukherjee@gmail.com',
      license='New BSD',
      long_description=longDescription,
      package_dir = {'d_hankel_t/': ''},
      packages=['d_hankel_t'],
      install_requires=['numpy']
      )
