#include "pch.h"
#include "CppUnitTest.h"
#include "../5,4/5,4.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest5
{
    TEST_CLASS(UnitTest5)
    {
    public:


        TEST_METHOD(TestF_Zero)
        {
            double t = f(0);
            Assert::AreEqual(0.0, t, 1e-9);
        }


        TEST_METHOD(TestF_One)
        {
            double expected = sqrt(1.0 / (1.0 + exp(-1.0)));
            double t = f(1);
            Assert::AreEqual(expected, t, 1e-9);
        }


        TEST_METHOD(TestF_Two)
        {
            double expected = sqrt(4.0 / (1.0 + exp(-2.0)));
            double t = f(2);
            Assert::AreEqual(expected, t, 1e-9);
        }


        TEST_METHOD(TestF_NegativeOne)
        {
            double expected = sqrt(1.0 / (1.0 + exp(1.0)));
            double t = f(-1);
            Assert::AreEqual(expected, t, 1e-9);
        }


        TEST_METHOD(TestS0_TwoElements)
        {
            double expected = sqrt(1.0 / (1.0 + exp(-1.0))) * sqrt(4.0 / (1.0 + exp(-2.0)));
            double t = S0(1, 2);
            Assert::AreEqual(expected, t, 1e-9);
        }


        TEST_METHOD(TestS0_RangeContainsZero)
        {
            double t = S0(-2, 2);
            Assert::AreEqual(0.0, t, 1e-9);
        }
    };
}