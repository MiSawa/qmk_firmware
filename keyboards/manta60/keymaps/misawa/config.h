/* Copyright 2020 kamonanban
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#pragma once

#define RGBLIGHT_SLEEP

// place overrides here

#define EE_HANDS // store handedness on EEPROM

#ifdef OLED_DRIVER_ENABLE

#ifndef SOFT_SERIAL_PIN
#define SOFT_SERIAL_PIN D2
#endif
#define USE_SERIAL_PD2

#define SERIAL_USE_MULTI_TRANSACTION
#define SSD1306OLED


#define OLED_TIMEOUT 10000
#define OLED_SCROLL_TIMEOUT 1000

#define ENABLE_SLAVE_OLED

#endif // OLED_ENABLED

