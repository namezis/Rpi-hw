/* 
	Title --- display/pcd8544.cpp

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


#ifndef _RPI_HW_DISPLAY_PCD8544_CPP_
#define _RPI_HW_DISPLAY_PCD8544_CPP_

#include <rpi-hw/display/pcd8544.hpp>

namespace rpihw { // Begin main namespace

namespace display { // Begin displays namespace

pcd8544::pcd8544( uint8_t sclk, uint8_t sdin, uint8_t dc, uint8_t sce, uint8_t rst )

	: pcd8544_skeleton	( { dc, rst, sce } )
	, m_data			( new iface::shiftOut( sdin, sclk, iface::shiftOut::MSBFIRST, 10000 ) ) {

}

pcd8544::~pcd8544() {

}

void
pcd8544::cmd( uint8_t data ) {

	// Set DC value to low
	m_control->write( DC, 0 );

	// Send the command to the display
	m_control->write( SCE, 0 );
	m_data->write( data );
	m_control->write( SCE, 1 );
}

void
pcd8544::sendData( uint8_t data ) {

	// Set DC value to high
	m_control->write( DC, 1 );

	// Send the data to the display
	m_control->write( SCE, 0 );
	m_data->write( data );
	m_control->write( SCE, 1 );
}

} // End of displays namespace

} // End of main namespace

#endif /* _RPI_HW_DISPLAY_PCD8544_CPP_ */
