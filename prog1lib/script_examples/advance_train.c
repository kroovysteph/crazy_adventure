/*
Compile: make advance_train
Run: ./advance_train
*/
 
#include "base.h"

/*
A critical section of a railway track has a length of 10 km. Trains pass through the cricital sections in both directions. At most one train is allowed on this critical section at any one time. A control system is to be implemented that provides the position of a train in that section (if there is one) or an indication that there is no train in that section. Define a data definition for this information. Define a function takes this data definition and advances the train's position by a given amount (in km). This may result in the train leaving the critical section.
*/

enum TrainTag {
    T_ABSENT,
    T_PRESENT
};
 
struct Train {
    enum TrainTag tag;
    // the distance from the start of the critical section (in km)
    double position;
};
 
struct Train make_train_none() { // constructor
    struct Train t = { T_ABSENT, 0.0 };
    return t;
}
 
struct Train make_train_at(double position) { // constructor
    struct Train t = { T_PRESENT, position };
    return t;
}

const double START_POSITION = 0.0;
const double END_POSITION = 10.0;

// struct Train, double -> struct Train
// Advance the train by the given amount. Consider the case
// that the train enters or leaves the critical section.
struct Train advance_train(struct Train train, double amount);

bool check_expect_i_line(int line, int actual, int expected) {
	return base_check_expect_i(__FILE__, __func__, line, actual, expected);
}

bool check_within_d_line(int line, double actual, double expected) {
	return base_check_within_d(__FILE__, __func__, line, actual, expected, EPSILON);
}

// helper function for comparing trains
bool check_expect_train(int line, struct Train t, struct Train s) {
    bool tags_equal = check_expect_i_line(line, t.tag, s.tag);
    bool values_within = check_within_d_line(line, t.position, s.position);
    return tags_equal && values_within;
}

static void advance_train_test() {
    // absent
    check_expect_train(__LINE__, advance_train(make_train_none(), 3.0),
                          make_train_none());
 
    // borders
    check_expect_train(__LINE__, advance_train(make_train_at(0.0), 0.0),
                          make_train_at(0.0));
    check_expect_train(__LINE__, advance_train(make_train_at(10.0), 0.0),
                          make_train_at(10.0));
    check_expect_train(__LINE__, advance_train(make_train_at(1.0), -1.0),
                          make_train_at(0.0));
    check_expect_train(__LINE__, advance_train(make_train_at(9.0), 1.0),
                          make_train_at(10.0));
 
    // interior (both before and after advance)
    check_expect_train(__LINE__, advance_train(make_train_at(1.0), 0.0),
                          make_train_at(1.0));
    check_expect_train(__LINE__, advance_train(make_train_at(5.5), 1.5),
                          make_train_at(7.0));
    check_expect_train(__LINE__, advance_train(make_train_at(4.5), -1.0),
                          make_train_at(3.5));
 
    // leaving the section
    check_expect_train(__LINE__, advance_train(make_train_at(9.0), 1.1),
                          make_train_none());
    check_expect_train(__LINE__, advance_train(make_train_at(1.0), -1.1),
                          make_train_none());
 
    // entering the section
    check_expect_train(__LINE__, advance_train(make_train_at(-0.1), 0.1),
                          make_train_at(0.0));
    check_expect_train(__LINE__, advance_train(make_train_at(10.1), -0.1),
                          make_train_at(10.0));
}

// Advance the train by the given amount. Consider the case
// that the train enters or leaves the critical section.
struct Train advance_train(struct Train train, double amount) {
    switch (train.tag) {
        case T_ABSENT:
            return make_train_none();
        case T_PRESENT:
            train.position += amount;
            if (train.position < START_POSITION ||
                train.position > END_POSITION) {
                return make_train_none();
            } else {
                return train;
            }
    }
    return train;
}

int main(void) {
    advance_train_test();
    return 0;
}



/*
1. Problem statement (given)
A critical section of a railway track has a length of 10 km. Trains pass through the cricital sections in both directions. At most one train is allowed on this critical section at any one time. A control system is to be implemented that provides the position of a train in that section (if there is one) or an indication that there is no train in that section. Define a data definition for this information. Define a function takes this data definition and advances the train's position by a given amount (in km). This may result in the train leaving the critical section.

2. Write a data definition
enum TrainTag {
    T_ABSENT,
    T_PRESENT
};
 
struct Train {
    enum TrainTag tag;
    // the distance from the start of the critical section (in km)
    double position;
};
 
struct Train make_train_none() { // constructor
    struct Train t = { T_ABSENT, 0.0 };
    return t;
}
 
struct Train make_train_at(double position) { // constructor
    struct Train t = { T_PRESENT, position };
    return t;
}

const double START_POSITION = 0.0;
const double END_POSITION = 10.0;

3. Write a function header
// struct Train, double -> struct Train
struct Train advance_train(struct Train train, double amount);

4. Write a purpose statement for the function
Advance the train by the given amount. Consider the case
that the train enters or leaves the critical section.

5. Give examples and expected results
Advancing a train that is not in the critical section (make_train_none()) by 3.0 km results in a train that is still not in the critical section (make_train_none()).
 
Advancing a train that is at the start of the critical section (make_train_at(0.0)) by 0.0 km results in a train that is still at the start of the critical section (make_train_at(0.0)).
 
Advancing a train that is at position 1.0 km of the critical section (make_train_at(1.0)) by -1.0 km results in a train that is at the start of the critical section (make_train_at(0.0)).
 
etc.

6. Implement the function body
struct Train advance_train(struct Train train, double amount) {
    switch (train.tag) {
        case T_ABSENT:
            return make_train_none();
        case T_PRESENT:
            train.position += amount;
            if (train.position < START_POSITION ||
                train.position > END_POSITION) {
                return make_train_none();
            } else {
                return train;
            }
    }
    return train;
}

7. Test the function
static void advance_train_test() {
	see above ...
}

int main(void) {
    advance_train_test();
    return 0;
}

8. Review and revise the function
no revision required
*/
