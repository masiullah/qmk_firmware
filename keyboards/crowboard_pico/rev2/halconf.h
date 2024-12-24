// Copyright 2022 jack (@waffle87)
// SPDX-License-Identifier: GPL-2.0-or-later
#pragma once
#define HAL_USE_I2C TRUE
#include_next <halconf.h>
#undef HAL_USE_PWM
#define HAL_USE_PWM TRUE