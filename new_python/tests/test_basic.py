import unittest
import sys
import os

sys.path.insert(0, os.getcwd() + "/../")
import igl
import inspect
import numpy as np
import scipy.sparse.csr as csr

class TestBasic(unittest.TestCase):

    def setUp(self):
        # Some global datastructures to use in the tests
        np.random.seed(42)
        self.v = np.random.rand(10, 3)
        self.t = np.random.rand(10, 4)
        self.f = np.random.randint(0, 10, size=(20, 3), dtype="int32")
        self.g = np.random.randint(0, 10, size=(20, 4), dtype="int32")

    def test_module(self):
        # Extract all implemented functions from the module
        funcs = []
        flist = ["helpers", "os", "print_usage", "pyigl", "viewer", "check_dependencies"]
        for att in dir(igl):
            if str.istitle(att[0]) or att[:2] == "__" or att in flist:
                continue
            else:
                funcs.append(att)
        funcs = sorted(funcs)

        # Extract all tests from this file
        tests = []
        flist = ["test_module"]
        for att in dir(self):
            if not att.startswith("test") or att in flist:
                continue
            else:
                tests.append(att[5:])

        # Check that there are tests for all functions
        for f in funcs:
            if f not in tests:
                print("WARNING: Test for function %s missing."%f)
                #self.assertTrue(f in tests)

    def test_adjacency_matrix(self):
        a = igl.adjacency_matrix(self.f)
        b = igl.adjacency_matrix(self.f, dtype="float32")
        self.assertTrue(a.shape == (self.v.shape[0], self.v.shape[0]))
        self.assertTrue(b.shape == (self.v.shape[0], self.v.shape[0]))
        self.assertTrue(b.dtype == np.float32)
        self.assertTrue(a.dtype == np.float64)
        self.assertTrue(type(a) == type(b) == csr.csr_matrix)


    def test_avg_edge_length(self):
        l = igl.avg_edge_length(self.v, self.f)
        #self.assertTrue(np.isclose(l, 0.591942059553195))


    def test_cotmatrix(self):
        l = igl.cotmatrix(self.v, self.f)
        m = igl.cotmatrix(self.v, self.f, dtype="float32")
        self.assertTrue(l.shape == (self.v.shape[0], self.v.shape[0]))
        self.assertTrue(m.shape == (self.v.shape[0], self.v.shape[0]))
        self.assertTrue(m.dtype == np.float32)
        self.assertTrue(l.dtype == np.float64)
        self.assertTrue(type(l) == type(m) == csr.csr_matrix)


    def test_gaussian_curvature(self):
        g = igl.gaussian_curvature(self.v, self.f)
        h = igl.gaussian_curvature(self.v, self.f, dtype="float32")
        self.assertTrue(g.shape == (self.v.shape[0], 1))
        self.assertTrue(h.shape == (self.v.shape[0], 1))
        self.assertTrue(h.dtype == np.float32)
        self.assertTrue(g.dtype == np.float64)
        self.assertTrue(type(g) == type(h) == np.ndarray)


    def test_grad(self):
        g = igl.grad(self.v, self.f)
        h = igl.grad(self.v, self.f, uniform=True)
        self.assertTrue(g.shape == (self.f.shape[0] * self.v.shape[1], self.v.shape[0]))
        self.assertTrue(h.shape == (self.f.shape[0] * self.v.shape[1], self.v.shape[0]))
        self.assertTrue(type(g) == type(h) == csr.csr_matrix)


    def test_jet(self):
        c = igl.jet(np.random.rand(1000), True)
        self.assertTrue(len(c) == 1000)
        self.assertTrue(np.min(c) >= 0.0)
        self.assertTrue(np.max(c) <= 1.0)


    def test_parula(self):
        c = igl.parula(np.random.rand(1000), True)
        self.assertTrue(len(c) == 1000)
        self.assertTrue(np.min(c) >= 0.0)
        self.assertTrue(np.max(c) <= 1.0)

if __name__ == '__main__':
    unittest.main()
