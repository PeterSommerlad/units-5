/****************************************************************************
 *       Copyright (C) 2017 Gaetano Mendola <mendola@gmail.com>             *
 * This work is free. You can redistribute it and/or modify it under the    *
 * terms of the Do What The Fuck You Want To Public License, Version 2,     *
 * as published by Sam Hocevar. See http://www.wtfpl.net/ for more details. *
 ****************************************************************************/

#pragma once

#include "units_base.h"

namespace uns {

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

}
