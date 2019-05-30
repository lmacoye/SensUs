from distutils.core import setup
from distutils.extension import Extension
from Cython.Distutils import build_ext
import numpy as np

ext_modules = [
    Extension('SDCM', ['SDCM.pyx'], language="c++", libraries=['SDCM'], library_dirs=['.'])]

setup(name='SDCM', cmdclass={'build_ext': build_ext},
      ext_modules=ext_modules, include_dirs=[np.get_include()])
