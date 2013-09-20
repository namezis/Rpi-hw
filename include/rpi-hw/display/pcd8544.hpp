/* 
    Title --- display/pcd8544.hpp

    Copyright (C) 2013 Giacomo Trudu - wicker25[at]gmail[dot]com

    This file is part of Rpi-hw.

    Rpi-hw is free software: you can redistribute it and/or modify
    it under the terms of the GNU Lesser General Public License as published by
    the Free Software Foundation version 3 of the License.

    Rpi-hw is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
    GNU Lesser General Public License for more details.

    You should have received a copy of the GNU Lesser General Public License
    along with Rpi-hw. If not, see <http://www.gnu.org/licenses/>.
*/


#ifndef _RPI_HW_DISPLAY_PCD8544_HPP_
#define _RPI_HW_DISPLAY_PCD8544_HPP_

#include <memory>

#include <rpi-hw/types.hpp>
#include <rpi-hw/exception.hpp>
#include <rpi-hw/math.hpp>

#include <rpi-hw/iface/shift-out.hpp>

#include <rpi-hw/display/pcd8544-skeleton.hpp>

namespace rpihw { // Begin main namespace

namespace display { // Begin displays namespace

/*!
	@class pcd8544
	@brief Philips PCD8544 LCD controller.

	@example display/pcd8544.cpp
*/
class pcd8544 : public pcd8544_skeleton {

public:

	/*!
		@brief Constructor method (4-bit mode).
		@param[in] sclk The GPIO pin connected to the sclk pin.
		@param[in] sdin The GPIO pin connected to the sda pin.
		@param[in] dc The GPIO pin connected to the dorc pin.
		@param[in] sce The GPIO pin connected to the cs pin.
		@param[in] rst The GPIO pin connected to the rst pin.
	*/
	pcd8544( uint8_t sclk, uint8_t sdin, uint8_t dc, uint8_t sce, uint8_t rst );

	//! Destructor method.
	virtual ~pcd8544();

	/*!
		@brief Sends a command to the display.
		@param[in] data The command.
	*/
	virtual void cmd( uint8_t data );

	/*!
		@brief Sends a data to the display.
		@param[in] data The 8-bit data to be sended.
	*/
	virtual void sendData( uint8_t data );

protected:

	//! Shift-out interface to the data pins.
	std::unique_ptr< iface::shiftOut > m_data;
};

} // End of displays namespace

} // End of main namespace


// Include inline methods 
#include <rpi-hw/display/pcd8544-inl.hpp>

#endif /* _RPI_HW_DISPLAY_PCD8544_HPP_ */
