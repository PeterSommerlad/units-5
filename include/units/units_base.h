/****************************************************************************
 *       Copyright (C) 2017 Gaetano Mendola <mendola@gmail.com>             *
 * This work is free. You can redistribute it and/or modify it under the    *
 * terms of the Do What The Fuck You Want To Public License, Version 2,     *
 * as published by Sam Hocevar. See http://www.wtfpl.net/ for more details. *
 ****************************************************************************/

#pragma once

namespace uns {

template <class TYPE, int L, int M, int T, int EC, int TT, int AOS, int LI>
class Value {
 public:
  explicit Value(TYPE aValue)
      :theValue(aValue)
  {
  }

  explicit operator TYPE() const {
    return theValue;
  }

  using type = TYPE;
  constexpr static int LV   = L;
  constexpr static int MV   = M;
  constexpr static int TV   = T;
  constexpr static int ECV  = EC;
  constexpr static int TTV  = TT;
  constexpr static int AOSV = AOS;
  constexpr static int LIV  = LI;
 private:
  TYPE theValue;
};

template<class UNIT1, class UNIT2>
struct UnitRatio {
  static_assert( std::is_same<typename UNIT1::type, typename UNIT2::type>::value );

  using type = Value<typename UNIT1::type,
                     UNIT1::LV   - UNIT2::LV,
                     UNIT1::MV   - UNIT2::MV,
                     UNIT1::TV   - UNIT2::TV,
                     UNIT1::ECV  - UNIT2::ECV,
                     UNIT1::TTV  - UNIT2::TTV,
                     UNIT1::AOSV - UNIT2::AOSV,
                     UNIT1::LIV  - UNIT2::LIV>;
};


template<class UNIT1, class UNIT2>
struct UnitProduct {
  static_assert( std::is_same<typename UNIT1::type, typename UNIT2::type>::value );

  using type = Value<typename UNIT1::type,
                     UNIT1::LV   + UNIT2::LV,
                     UNIT1::MV   + UNIT2::MV,
                     UNIT1::TV   + UNIT2::TV,
                     UNIT1::ECV  + UNIT2::ECV,
                     UNIT1::TTV  + UNIT2::TTV,
                     UNIT1::AOSV + UNIT2::AOSV,
                     UNIT1::LIV  + UNIT2::LIV>;
};



template <class TYPE> using Length                  = Value<TYPE, 1, 0, 0, 0, 0, 0, 0>;
template <class TYPE> using Mass                    = Value<TYPE, 0, 1, 0, 0, 0, 0, 0>;
template <class TYPE> using Time                    = Value<TYPE, 0, 0, 1, 0, 0, 0, 0>;
template <class TYPE> using ElectrictCurrent        = Value<TYPE, 0, 0, 0, 1, 0, 0, 0>;
template <class TYPE> using TermodynamicTemperature = Value<TYPE, 0, 0, 0, 0, 1, 0, 0>;
template <class TYPE> using AmountOfSubstance       = Value<TYPE, 0, 0, 0, 0, 0, 1, 0>;
template <class TYPE> using LuminosityIntensity     = Value<TYPE, 0, 0, 0, 0, 0, 0, 1>;

template <class TYPE> using Frequency    = Value<TYPE, 0,  0, -1, 0, 0, 0, 0>;
template <class TYPE> using Velocity     = typename UnitRatio<Length<TYPE>, Time<TYPE>>::type;
template <class TYPE> using Acceleration = typename UnitRatio<Velocity<TYPE>, Time<TYPE>>::type;



template <class UNIT1, class UNIT2>
auto operator*(const UNIT1& aLeft, const UNIT2& aRight) {
  static_assert( std::is_same<typename UNIT1::type, typename UNIT2::type>::value );
  using TYPE = typename UNIT1::type;
  return typename UnitProduct<UNIT1, UNIT2>::type(static_cast<TYPE>(aLeft) * static_cast<TYPE>(aRight));
}

template <class UNIT1, class UNIT2>
auto operator/(const UNIT1& aLeft, const UNIT2& aRight) {
  static_assert( std::is_same<typename UNIT1::type, typename UNIT2::type>::value );
  using TYPE = typename UNIT1::type;
  return typename UnitRatio<UNIT1, UNIT2>::type(static_cast<TYPE>(aLeft) / static_cast<TYPE>(aRight));
}

template <class TYPE, int L, int M, int T, int EC, int TT, int AOS, int LI>
auto operator+(const Value<TYPE, L, M, T, EC, TT, AOS, LI>& aLeft,
               const Value<TYPE, L, M, T, EC, TT, AOS, LI>& aRight) {
  return Value<TYPE, L, M, T, EC, TT, AOS, LI>(static_cast<TYPE>(aLeft) + static_cast<float>(aRight));
}

template <class TYPE, int L, int M, int T, int EC, int TT, int AOS, int LI>
auto operator-(const Value<TYPE, L, M, T, EC, TT, AOS, LI>& aLeft,
               const Value<TYPE, L, M, T, EC, TT, AOS, LI>& aRight) {
  return Value<TYPE, L, M, T, EC, TT, AOS, LI>(static_cast<TYPE>(aLeft) - static_cast<float>(aRight));
}

}
