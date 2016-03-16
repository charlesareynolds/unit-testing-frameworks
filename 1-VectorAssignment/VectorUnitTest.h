// Supporting types and functions for vector testing examples
#ifndef VectorUnitTest_H
#define VectorUnitTest_H

#include <boost/foreach.hpp>
#include <exception>
#include <iostream>
#include <string>
#include <vector>

namespace VectorUnitTest {

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//                                      Types for testing std::vector
//
// Assume that these could change after your tests are written. I.e., pretend they're some ROSE types that could evolve.
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// First std::vector element type for testing
typedef int T1;

// Second std::vector element type for testing. If causeCopyError is true then the copy c'tor throws an exception.
struct T2 {
    bool causeCopyError;                                // not propagated across copies
    int member;

    T2(): causeCopyError(false), member(-1) {}

    explicit T2(int member): causeCopyError(false), member(member) {}

    T2(const T2 &other): causeCopyError(false), member(-2) {
        if (other.causeCopyError)
            throw std::runtime_error("pretending that T2's copy c'tor failed");
        member = other.member;
    }

    T2& operator=(T2 other) {
        member = other.member;
        return *this;
    }

    bool operator==(const T2 &other) const {
        return member == other.member;
    }

    friend std::ostream& operator<<(std::ostream &out, const T2 &x) {
        out <<x.member;
        return out;
    }
};

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//                                      Support functions for printing vectors
//
// Use these printVector if you like or create your own.  They don't count against the complexity of your test because every
// class we test will likely need its own way of printing its details anyway. In reality, we'd be testing a ROSE container
// instead of std::vector, in which case the functions to print the details are probably part of the container's API
// already (or should be).
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

template<class T>
std::string
printVector(const std::vector<T> &v, size_t idx = size_t(-1), const std::string &mesg = "unit test failed") {
    std::cerr <<"vector = [";
    BOOST_FOREACH (const T& t, v)
        std::cerr <<" " <<t;
    std::cerr <<" ]";
    if (idx != size_t(-1)) {
        if (idx < v.size()) {
            std::cerr <<"; vector[" <<idx <<"] = " <<v[idx];
        } else {
            std::cerr <<"; index " <<idx <<" is out of bounds";
        }
    }
    std::cerr <<std::endl;
    return mesg;
}

template<class T>
std::string
printVector(const std::vector<T> &v1, const std::vector<T> &v2, const std::string &mesg = "unit test failed") {
    printVector(v1, size_t(-1), "");
    printVector(v2, size_t(-1), "");
    return mesg;
}

template<class T>
std::string
printVector(const std::vector<T> &v1, size_t idx1,
            const std::vector<T> &v2, size_t idx2, const std::string &mesg = "unit test failed") {
    printVector(v1, idx1, "");
    printVector(v2, idx2, "");
    return mesg;
}

} // namespace

#endif
