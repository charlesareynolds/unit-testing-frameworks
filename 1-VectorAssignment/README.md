## Vector Assignment Unit Test

std::vector is a stand-in for some ROSE template class.  We want to
check that this class has a proper assignment operator with strong
exception safety guarantee. Therefore, test both of these:

1. After the assignment, the destination vector is the same size as the source and
   has elements that compare equal (T::operator==) to the source elements, or

2. If any exception is thrown (such as vector allocation error or T's
   copy constructor error) that the destination is unchanged.
   Actually, std::vector only has basic exception safety, so expect
   this test to fail (it will copy up to the exception).

Your test may assume all of the following:

a. T has a default constructor
b. T has copy constructor that sometimes throws an exception
c. T has an operator==
d. T is printable via operator<<(std::ostream&, const T&)
e. T has been tested already
f. whatever features of std::vector you need have been tested already

If in doubt, look at the sawyer test for guidance.
