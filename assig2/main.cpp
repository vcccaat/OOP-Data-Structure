#define private public

#include "buddy.h"
#include <fstream>

using namespace std;

bool equal(const Dining& x, const Dining& y) {
    if (x.getName() != y.getName())
        return false;
    if (x.getFat() != y.getFat())
        return false;
    if (x.getEnergy() != y.getEnergy())
        return false;
    if (x.getPrice() != y.getPrice())
        return false;
    return true;
}

bool equal(const Workout& x, const Workout& y) {
    if (x.getName() != y.getName())
        return false;
    if (x.getEnergyChange() != y.getEnergyChange())
        return false;
    if (x.getFatChange() != y.getFatChange())
        return false;
    if (x.getMuscleChange() != y.getMuscleChange())
        return false;
    return true;
}

/*
 * class Dining 
 * */
// Dining: operator+
int test_dining_add(int num, int& max_score)
{
    int score = 0;
    max_score = 1;
    try {
        Dining d1("a", 10, 20, 30);
        Dining d1_("a", 10, 20, 30);
        Dining d2("b", 2, 8, 16);
        Dining d2_("b", 2, 8, 16);
        Dining d3("", 1, 2, 3);
        Dining d3_("", 1, 2, 3);
        Dining d4("a", 33, 22, 11);
        Dining d4_("a", 33, 22, 11);

        if (num == 0) {
            Dining s1 = d1 + d2;
            Dining s2("ab", 12, 28, 46);
            if (equal(s1, s2) && equal(d1, d1_) && equal(d2, d2_))
                score = 1;
        } else if (num == 1) {
            Dining s1 = d1 + d4;
            Dining s2("a", 43, 42, 41);
            if (equal(s1, s2) && equal(d1, d1_) && equal(d4, d4_))
                score = 1;
        } else if (num == 2) {
            Dining s1 = d2 + d3;
            Dining s2("b", 3, 10, 19);
            if (equal(s1, s2) && equal(d2, d2_) && equal(d3, d3_))
                score = 1;
        }
    } catch(...) {
        return score;
    }

    return score;
}

// Dining: operator+=
int test_dining_addequal(int num, int& max_score)
{
    int score = 0;
    max_score = 1;
    try {
        Dining d1("a", 10, 20, 30);
        Dining d1_("a", 10, 20, 30);
        Dining d2("b", 2, 8, 16);
        Dining d2_("b", 2, 8, 16);
        Dining d3("", 1, 2, 3);
        Dining d3_("", 1, 2, 3);
        Dining d4("a", 33, 22, 11);
        Dining d4_("a", 33, 22, 11);

        if (num == 0) {
            d1 += d2;
            Dining s2("ab", 12, 28, 46);
            if (equal(d1, s2) && equal(d2, d2_))
                score = 1;
        } else if (num == 1) {
            d1 += d4;
            Dining s2("a", 43, 42, 41);
            if (equal(d1, s2) && equal(d4, d4_))
                score = 1;
        } else if (num == 2) {
            d2 += d3;
            Dining s2("b", 3, 10, 19);
            if (equal(d2, s2) && equal(d3, d3_))
                score = 1;
        }
    } catch(...) {
        return score;
    }

    return score;
}

// Dining: operator= 
int test_dining_equal(int num, int& max_score)
{
    int score = 0;
    max_score = 1;
    try {
        Dining d1("a", 10, 20, 30);
        Dining d1_("a", 10, 20, 30);
        Dining d2("b", 2, 8, 16);
        Dining d2_("b", 2, 8, 16);
        Dining d3("", 1, 2, 3);
        Dining d3_("", 1, 2, 3);

        if (num == 0) {
            d1 = d2;
            if (equal(d1, d2_) && equal(d2, d2_))
                score = 1;
        } else if (num == 1) {
            d1 = d3;
            if (equal(d1, d3_) && equal(d3, d3_))
                score = 1;
        }
    } catch(...) {
        return score;
    }

    return score;
}

/*
 * class Workout 
 * */

// Workout: operator+
int test_workout_add(int num, int& max_score)
{
    int score = 0;
    max_score = 1;
    try {
        Workout d1("a", 10, 20, 30);
        Workout d1_("a", 10, 20, 30);
        Workout d2("b", 2, 8, 16);
        Workout d2_("b", 2, 8, 16);
        Workout d3("", 1, 2, 3);
        Workout d3_("", 1, 2, 3);
        Workout d4("a", 33, 22, 11);
        Workout d4_("a", 33, 22, 11);

        if (num == 0) {
            Workout s1 = d1 + d2;
            Workout s2("ab", 12, 28, 46);
            if (equal(s1, s2) && equal(d1, d1_) && equal(d2, d2_))
                score = 1;
        } else if (num == 1) {
            Workout s1 = d1 + d4;
            Workout s2("a", 43, 42, 41);
            if (equal(s1, s2) && equal(d1, d1_) && equal(d4, d4_))
                score = 1;
        } else if (num == 2) {
            Workout s1 = d2 + d3;
            Workout s2("b", 3, 10, 19);
            if (equal(s1, s2) && equal(d2, d2_) && equal(d3, d3_))
                score = 1;
        }
    } catch(...) {
        return score;
    }

    return score;
}

// Workout: operator+=
int test_workout_addequal(int num, int& max_score)
{
    int score = 0;
    max_score = 1;
    try {
        Workout d1("a", 10, 20, 30);
        Workout d1_("a", 10, 20, 30);
        Workout d2("b", 2, 8, 16);
        Workout d2_("b", 2, 8, 16);
        Workout d3("", 1, 2, 3);
        Workout d3_("", 1, 2, 3);
        Workout d4("a", 33, 22, 11);
        Workout d4_("a", 33, 22, 11);

        if (num == 0) {
            d1 += d2;
            Workout s2("ab", 12, 28, 46);
            if (equal(d1, s2) && equal(d2, d2_))
                score = 1;
        } else if (num == 1) {
            d1 += d4;
            Workout s2("a", 43, 42, 41);
            if (equal(d1, s2) && equal(d4, d4_))
                score = 1;
        } else if (num == 2) {
            d2 += d3;
            Workout s2("b", 3, 10, 19);
            if (equal(d2, s2) && equal(d3, d3_))
                score = 1;
        }
    } catch(...) {
        return score;
    }

    return score;
}

// Workout: operator= 
int test_workout_equal(int num, int& max_score)
{
    int score = 0;
    max_score = 1;
    try {
        Workout d1("a", 10, 20, 30);
        Workout d1_("a", 10, 20, 30);
        Workout d2("b", 2, 8, 16);
        Workout d2_("b", 2, 8, 16);
        Workout d3("", 1, 2, 3);
        Workout d3_("", 1, 2, 3);

        if (num == 0) {
            d1 = d2;
            if (equal(d1, d2_) && equal(d2, d2_))
                score = 1;
        } else if (num == 1) {
            d1 = d3;
            if (equal(d1, d3_) && equal(d3, d3_))
                score = 1;
        }
    } catch(...) {
        return score;
    }

    return score;
}

/*
 * class Schedule 
 * */

// Schedule: size
template <typename T>
int test_size(int num, int& max_score)
{
    int score = 0;
    max_score = 1;
    try {
        Schedule<T> s = Schedule<T>();
        s.values[make_pair(1,2)] = T();
        s.values[make_pair(3,4)] = T();
        if (s.size() == 2)
            score++;
    } catch (...) {
        return score;
    }

    return score;
}

// Schedule: operator() 
template <typename T>
int test_parenthesis(int num, int& max_score)
{
    int score = 0;
    max_score = 1;
    try {
        Schedule<T> s = Schedule<T>();
        T t1("a", 1, 2, 3);
        T t2("b", 2, 3, 4);
        T t3("c", 3, 4, 5);
        T t4("d", 4, 5, 7);
        
        s.values[make_pair(1,2)] = t1;
        s.values[make_pair(3,4)] = t2;
        s.values[make_pair(5,7)] = t3;
        s.values[make_pair(8,10)] = t4;

        if (num == 0) {
            if (s(5, 5).size() == 0 && s(6, 5).size() == 0)
                score = 1;
        } else if (num == 1) {
            vector<T> out = s(1, 2);
            if (out.size() == 1 && equal(out[0], t1))
                score = 1;
        } else if (num == 2) {
            vector<T> out = s(1, 4);
            if (out.size() == 2 && equal(out[0], t1) && equal(out[1], t2))
                score = 1; 
        } else if (num == 3) {
            if (s(6, 9).size() == 0)
                score = 1;
        } else if (num == 4) {
            vector<T> out = s(6, 11);
            if (out.size() == 1 && equal(out[0], t4))
                score = 1;
        }
    } catch (...) {
        return score;
    }

    return score;
}

// Schedule: isFree 
template <typename T>
int test_isfree(int num, int& max_score)
{
    int score = 0;
    max_score = 4;
    try {
        Schedule<T> s = Schedule<T>();
        T t1("a", 1, 2, 3);
        T t2("b", 2, 3, 4);
        
        s.values[make_pair(1,2)] = t1;
        s.values[make_pair(3,5)] = t2;

        if (s.isFree(1, 2) == false)
            score++;
        if (s.isFree(2, 3) == true)
            score++;
        if (s.isFree(3, 2) == false)
            score++;
        if (s.isFree(2, 4) == false)
            score++;
    } catch (...) {
        return score;
    }

    return score;
}

// Schedule: mergeSameContinuous 
template <typename T>
int test_merge(int num, int& max_score)
{
    int score = 0;
    max_score = 2;
    try {
        Schedule<T> s = Schedule<T>();
        T t1("a", 1, 2, 3);
        T t2("b", 2, 3, 4);
        T t3("a", 3, 4, 5);
        T t4("a", 4, 5, 7);

        if (num == 0) {
            s.values[make_pair(1,2)] = t1;
            s.values[make_pair(3,4)] = t2;
            s.mergeSameContinuous();
            if (s.values.size() == 2)
                score++; cout<<"pass1"<<endl;
            if (equal(s.values[make_pair(1,2)], t1) && equal(s.values[make_pair(3,4)], t2))
                score++;
        } else if (num == 1) {
            s.values[make_pair(1,2)] = t1;
            s.values[make_pair(2,3)] = t2;
            s.mergeSameContinuous();
            if (s.values.size() == 2)
                score++; cout<<"pass1"<<endl;
            if (equal(s.values[make_pair(1,2)], t1) && equal(s.values[make_pair(2,3)], t2))
                score++; cout<<"pass1"<<endl;
        } else if (num == 2) {
            s.values[make_pair(1,2)] = t1;
            s.values[make_pair(2,3)] = t3;
            s.values[make_pair(3,4)] = t4;
            s.mergeSameContinuous();
            if (s.values.size() == 1)
                {score++; cout<<"pass1"<<endl;}
            if (equal(s.values[make_pair(1,4)], T("a", 8, 11, 15)))
                {score++; cout<<"pass2"<<endl;}
        }
    } catch (...) {
        return score;
    }

    return score;
}

// Schedule: insert 
template <typename T>
int test_insert(int num, int& max_score)
{
    int score = 0;
    max_score = 1;
    try {
        Schedule<T> s = Schedule<T>();
        T t1("a", 1, 2, 3);
        T t2("b", 2, 3, 4);
        T t3("a", 3, 4, 5);
        T t4("a", 4, 5, 7);
        
        s.values[make_pair(1,2)] = t1;
        s.values[make_pair(3,4)] = t2;
        s.values[make_pair(5,7)] = t3;
        s.values[make_pair(8,10)] = t4;

        if (num == 0) {
            s.insert(2, 4, t1);
            if (s.values.size() == 4 
                && equal(s.values[make_pair(1,2)], t1) && equal(s.values[make_pair(3,4)], t2)
                && equal(s.values[make_pair(5,7)], t3) && equal(s.values[make_pair(8,10)], t4))
                score = 1;
        } else if (num == 1) {
            s.insert(2, 3, t1);
            if (s.values.size() == 4 
                && equal(s.values[make_pair(1,3)], T("a", 2, 4, 6)) && equal(s.values[make_pair(3,4)], t2)
                && equal(s.values[make_pair(5,7)], t3) && equal(s.values[make_pair(8,10)], t4))
                score = 1;
        } else if (num == 2) {
            s.insert(7, 8, t1);
            if (s.values.size() == 3 
                && equal(s.values[make_pair(1,2)], t1) && equal(s.values[make_pair(3,4)], t2)
                && equal(s.values[make_pair(5,10)], T("a", 8, 11, 15)))
                score = 1;
        }
    } catch (...) {
        return score;
    }

    return score;   
}

// Schedule: remove(start,end) 
template <typename T>
int test_remove_interval(int num, int& max_score)
{
    int score = 0;
    max_score = 1;
    try {
        Schedule<T> s = Schedule<T>();
        T t1("a", 1, 2, 3);
        T t2("b", 2, 3, 4);
        T t3("a", 3, 4, 5);
        T t4("a", 4, 5, 7);
        
        s.values[make_pair(1,2)] = t1;
        s.values[make_pair(3,4)] = t2;
        s.values[make_pair(5,7)] = t3;
        s.values[make_pair(8,10)] = t4;

        if (num == 0) {
            bool result = s.remove(7, 5);
            if (result == false && s.values.size() == 4
                && equal(s.values[make_pair(1,2)], t1) && equal(s.values[make_pair(3,4)], t2)
                && equal(s.values[make_pair(5,7)], t3) && equal(s.values[make_pair(8,10)], t4))
                score = 1;
        } else if (num == 1) {
            bool result = s.remove(6, 9);
            if (result == true && s.values.size() == 4
                && equal(s.values[make_pair(1,2)], t1) && equal(s.values[make_pair(3,4)], t2)
                && equal(s.values[make_pair(5,7)], t3) && equal(s.values[make_pair(8,10)], t4))
                score = 1;
        } else if (num == 2) {
            bool result = s.remove(3, 5);
            if (result == true && s.values.size() == 3
                && equal(s.values[make_pair(1,2)], t1)
                && equal(s.values[make_pair(5,7)], t3) && equal(s.values[make_pair(8,10)], t4))
                score = 1;
        } else if (num == 3) {
            bool result = s.remove(3, 7);
            if (result == true && s.values.size() == 2
                && equal(s.values[make_pair(1,2)], t1) && equal(s.values[make_pair(8,10)], t4))
                score = 1;
        }
    } catch (...) {
        return score;
    }

    return score;   
}

// Schedule: remove(name) 
template <typename T>
int test_remove_name(int num, int& max_score)
{
    int score = 0;
    max_score = 1;
    try {
        Schedule<T> s = Schedule<T>();
        T t1("a", 1, 2, 3);
        T t2("b", 2, 3, 4);
        T t3("a", 3, 4, 5);
        T t4("a", 4, 5, 7);
        
        s.values[make_pair(1,2)] = t1;
        s.values[make_pair(3,4)] = t2;
        s.values[make_pair(5,7)] = t3;
        s.values[make_pair(8,10)] = t4;

        if (num == 0) {
            s.remove("c");
            if (s.values.size() == 4
                && equal(s.values[make_pair(1,2)], t1) && equal(s.values[make_pair(3,4)], t2)
                && equal(s.values[make_pair(5,7)], t3) && equal(s.values[make_pair(8,10)], t4))
                score = 1;
        } else if (num == 1) {
            s.remove("b");
            if (s.values.size() == 3
                && equal(s.values[make_pair(1,2)], t1)
                && equal(s.values[make_pair(5,7)], t3) && equal(s.values[make_pair(8,10)], t4))
                score = 1;
        } else if (num == 2) {
            s.remove("a");
            if (s.values.size() == 1
                && equal(s.values[make_pair(3,4)], t2))
                score = 1;
        }
    } catch (...) {
        return score;
    }

    return score;
}

// Schedule: summarize
template <typename T>
int test_summarize(int num, int& max_score)
{
    int score = 0;
    max_score = (num == 0) ? 2 : 3;
    try {
        Schedule<T> s = Schedule<T>();
        T t1("a", 1, 2, 3);
        T t2("b", 2, 3, 4);
        T t3("a", 3, 4, 5);
        T t4("a", 4, 5, 7);
        
        s.values[make_pair(1,2)] = t1;
        s.values[make_pair(3,4)] = t2;
        s.values[make_pair(5,7)] = t3;
        s.values[make_pair(8,10)] = t4;

        int total_time;
        if (num == 0) {
            T result = s.summarize("c", total_time);
            if (total_time == 0)
                score++;
            if (s.values.size() == 4
                && equal(s.values[make_pair(1,2)], t1) && equal(s.values[make_pair(3,4)], t2)
                && equal(s.values[make_pair(5,7)], t3) && equal(s.values[make_pair(8,10)], t4))
                score++;
        } else if (num == 1) {
            total_time = 0;
            T result = s.summarize("b", total_time);
            if (total_time == 1)
                score++;
            if (s.values.size() == 4
                && equal(s.values[make_pair(1,2)], t1) && equal(s.values[make_pair(3,4)], t2)
                && equal(s.values[make_pair(5,7)], t3) && equal(s.values[make_pair(8,10)], t4))
                score++;
            if (equal(result, t2))
                score++;
        } else if (num == 2) {
            total_time = 0;
            T result = s.summarize("a", total_time);
            if (total_time == 5)
                score++;
            if (s.values.size() == 4
                && equal(s.values[make_pair(1,2)], t1) && equal(s.values[make_pair(3,4)], t2)
                && equal(s.values[make_pair(5,7)], t3) && equal(s.values[make_pair(8,10)], t4))
                score++;
            if (equal(result, T("a", 8, 11, 15)))
                score++;
        }
    } catch (...) {
        return score;
    }

    return score;
}

/*
 * class Buddy 
 * */

// Buddy: capable(dining activity)
int test_capable_dining(int num, int& max_score)
{
    int score = 0;
    max_score = 1;
    typedef Dining T;
    try {
        Buddy tom = Buddy("Tom", 100, 100, 100, 100);
        
        T t1("a", 1, 2, 3);
        T t2("b", 2, 3, 4);

        tom.dining_schedule.values[make_pair(1,2)] = t1;
        tom.dining_schedule.values[make_pair(3,4)] = t2;

        if (num == 0) {
            T t("a", 1, 1, 1);
            Activity<T> act = Activity<T>(1, 2, t);
            score = (tom.capable(act) == false);
        } else if (num == 1) {
            T t("a", 1, 1, 1);
            Activity<T> act = Activity<T>(2, 3, t);
            score = (tom.capable(act) == true);
        } else if (num == 2) {
            T t("a", 1, 1, 101);
            Activity<T> act = Activity<T>(2, 3, t);
            score = (tom.capable(act) == false);                    
        }
    } catch (...) {
        return score;
    }
    return score;
}

// Buddy: capable(workout activity) capable(dining activity)
int test_capable_workout(int num, int& max_score)
{
    int score = 0;
    max_score = 1;
    typedef Workout T;
    try {
        Buddy tom = Buddy("Tom", 100, 100, 100, 100);
        
        T t1("a", 1, 2, 3);
        T t2("b", 2, 3, 4);

        tom.workout_schedule.values[make_pair(1,2)] = t1;
        tom.workout_schedule.values[make_pair(3,4)] = t2;

        if (num == 0) {
            T t("a", 1, 1, 1);
            Activity<T> act = Activity<T>(1, 2, t);
            score = (tom.capable(act) == false);
        } else if (num == 1) {
            T t("a", 1, 1, 1);
            Activity<T> act = Activity<T>(2, 3, t);
            score = (tom.capable(act) == true);
        } else if (num == 2) {
            T t("a", -101, -101, -101);
            Activity<T> act = Activity<T>(2, 3, t);
            score = (tom.capable(act) == false);                    
        }
    } catch (...) {
        return score;
    }
    return score;
}

// operator<<(workout activity)
int test_insert_dining(int num, int& max_score)
{
    int score = 0;
    max_score = 2;
    typedef Dining T;
    try {
        // fat muscle energy money
        Buddy tom = Buddy("Tom", 100, 100, 100, 100);
        
        T t1("a", 1, 2, 3);

        tom.dining_schedule.values[make_pair(1,2)] = t1;

        if (num == 0) {
            // fat energy price
            T t("b", 1, 2, 3);
            Activity<T> act = Activity<T>(3, 4, t);
            tom << act;
            if (tom.getFat() == 101
               && tom.getMuscle() == 100
               && tom.getEnergy() == 102
               && tom.getMoney() == 97)
                score++;
            
            if (tom.dining_schedule.values.size() == 2 
               && equal(tom.dining_schedule.values[make_pair(1, 2)], t1)
               && equal(tom.dining_schedule.values[make_pair(3, 4)], t))
                score++;
            
        } else if (num == 1) {
            // fat energy price
            T t("b", 1, 1, 101);
            Activity<T> act = Activity<T>(3, 4, t);
            tom << act;
            if (tom.getFat() == 100
               && tom.getMuscle() == 100
               && tom.getEnergy() == 100
               && tom.getMoney() == 100)
                score++;
            
            if (tom.dining_schedule.values.size() == 1 
               && equal(tom.dining_schedule.values[make_pair(1, 2)], t1))
                score++;
        }
    } catch (...) {
        return score;
    }
    return score;
}

// operator<<(dining activity)
int test_insert_workout(int num, int& max_score)
{
    int score = 0;
    max_score = 2;
    typedef Workout T;
    try {
        // fat muscle energy money
        Buddy tom = Buddy("Tom", 100, 100, 100, 100);
        
        T t1("a", 1, 2, 3);

        tom.workout_schedule.values[make_pair(1,2)] = t1;

        if (num == 0) {
            // fat_change muscle_change energy_change
            T t("b", -1, -2, -3);
            Activity<T> act = Activity<T>(3, 4, t);
            tom << act;
            if (tom.getFat() == 99
               && tom.getMuscle() == 98
               && tom.getEnergy() == 97
               && tom.getMoney() == 100)
                score++;
            
            if (tom.workout_schedule.values.size() == 2 
               && equal(tom.workout_schedule.values[make_pair(1, 2)], t1)
               && equal(tom.workout_schedule.values[make_pair(3, 4)], t))
                score++;
            
        } else if (num == 1) {
            // fat_change muscle_change energy_change
            T t("b", -1, -1, -101);
            Activity<T> act = Activity<T>(3, 4, t);
            tom << act;
            if (tom.getFat() == 100
               && tom.getMuscle() == 100
               && tom.getEnergy() == 100
               && tom.getMoney() == 100)
                score++;
            
            if (tom.workout_schedule.values.size() == 1 
               && equal(tom.workout_schedule.values[make_pair(1, 2)], t1))
                score++;
        }
    } catch (...) {
        return score;
    }
    return score;
}


void checkpoint(vector<int>& scores, vector<int>& max_scores, int& score, int& max_score, string description)
{
    cout << score << "/" << max_score << "\t" << description << endl;
    scores.push_back(score);
    score = 0;
    max_scores.push_back(max_score);
    max_score = 0;
}

int main() {
    // 0 <= index <= 71
    int index = 38;
    
    vector<int> scores, max_scores;
    vector<string> testcases = {
        "Dining operator+", "Dining operator+=", "Dining operator=", 
        "Workout operator+", "Workout operator+=", "Workout operator=",

        "Schedule<Dining> size", "Schedule<Workout> size",
        "Schedule<Dining> operator()", "Schedule<Workout> operator()",
        "Schedule<Dining> isFree", "Schedule<Workout> isFree",
        "Schedule<Dining> mergeSameContinuous", "Schedule<Workout> mergeSameContinuous",
        "Schedule<Dining> insert", "Schedule<Workout> insert",
        "Schedule<Dining> remove(start end)", "Schedule<Workout> remove(start end)",
        "Schedule<Dining> remove(name)", "Schedule<Workout> remove(name)",
        "Schedule<Dining> summarize", "Schedule<Workout> summarize",

        "Buddy capable Dining", "Buddy capable Workout", 
        "Buddy insert Dining", "Buddy insert Workout"
    };
    
    vector<int> offsets = {
        0, 3, 6,
        8, 11, 14,
        
        16, 17,
        18, 23,
        28, 29,
        30, 33,
        36, 39,
        42, 46,
        50, 53,
        56, 59,
        
        62, 65,
        68, 70
    };
    

    int score = 0;
    int max_score = 0;
    
   if (index < offsets[1]) {
       score = test_dining_add(index-offsets[0], max_score);
   } else if (index < offsets[2]) {
       score = test_dining_addequal(index-offsets[1], max_score);
   } else if (index < offsets[3]) {
       score = test_dining_equal(index-offsets[2], max_score);
   } else if (index < offsets[4]) {
       score = test_workout_add(index-offsets[3], max_score);
   } else if (index < offsets[5]) {
       score = test_workout_addequal(index-offsets[4], max_score);
   } else if (index < offsets[6]) {
       score = test_workout_equal(index-offsets[5], max_score);
   } else if (index < offsets[7]) {
       score = test_size<Dining>(index-offsets[6], max_score);
   } else if (index < offsets[8]) {
       score = test_size<Workout>(index-offsets[7], max_score);
   } else if (index < offsets[9]) {
       score = test_parenthesis<Dining>(index-offsets[8], max_score);
   } else if (index < offsets[10]) {
       score = test_parenthesis<Workout>(index-offsets[9], max_score);
   } else if (index < offsets[11]) {
       score = test_isfree<Dining>(index-offsets[10], max_score);
   } else if (index < offsets[12]) {
       score = test_isfree<Workout>(index-offsets[11], max_score);
   } else if (index < offsets[13]) {
       score = test_merge<Dining>(index-offsets[12], max_score);
   } else if (index < offsets[14]) {
       score = test_merge<Workout>(index-offsets[13], max_score);
   } else if (index < offsets[15]) {
       score = test_insert<Dining>(index-offsets[14], max_score);
   } else if (index < offsets[16]) {
       score = test_insert<Workout>(index-offsets[15], max_score);
   } else if (index < offsets[17]) {
       score = test_remove_interval<Dining>(index-offsets[16], max_score);
   } else if (index < offsets[18]) {
       score = test_remove_interval<Workout>(index-offsets[17], max_score);
   } else if (index < offsets[19]) {
       score = test_remove_name<Dining>(index-offsets[18], max_score);
   } else if (index < offsets[20]) {
       score = test_remove_name<Workout>(index-offsets[19], max_score);
   } else if (index < offsets[21]) {
       score = test_summarize<Dining>(index-offsets[20], max_score);
   } else if (index < offsets[22]) {
       score = test_summarize<Workout>(index-offsets[21], max_score);
   } else if (index < offsets[23]) {
       score = test_capable_dining(index-offsets[22], max_score);
   } else if (index < offsets[24]) {
       score = test_capable_workout(index-offsets[23], max_score);
   } else if (index < offsets[25]) {
       score = test_insert_dining(index-offsets[24], max_score);
   } else {
       score = test_insert_workout(index-offsets[25], max_score);
   }


    cout << "[The END] testcases " << index << ": " << score << "/" << max_score << endl;

    return 0;
}
