#pragma once
#include <chrono>

namespace bear
{
using std::chrono::system_clock;
using namespace std::literals::chrono_literals;

typedef std::chrono::nanoseconds   Nanosecond;
typedef std::chrono::microseconds  Microsecond;
typedef std::chrono::milliseconds  Millisecond;
typedef std::chrono::seconds       Second;
typedef std::chrono::minutes       Minute;
typedef std::chrono::hours         Hour;
typedef std::chrono::time_point
        <system_clock, Nanosecond> Timestamp;

namespace clock
{
inline Timestamp now() 
{return system_clock::now();} 

inline Timestamp nowAfter(Nanosecond interval)
{ return now() + interval; }

inline Timestamp nowBefore(Nanosecond interval)
{ return now() - interval; }
} // namespace clock

template <typename T>
struct IntervalTypeCheckImpl
{
    static constexpr bool value =
            std::is_same<T, Nanosecond>::value ||
            std::is_same<T, Microsecond>::value ||
            std::is_same<T, Millisecond>::value ||
            std::is_same<T, Second>::value ||
            std::is_same<T, Minute>::value ||
            std::is_same<T, Hour>::value;
};

}

