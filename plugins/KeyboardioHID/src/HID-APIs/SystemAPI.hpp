/*
Copyright (c) 2014-2015 NicoHood
See the readme for credit to other people.

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in
all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
THE SOFTWARE.
*/

// Include guard
#pragma once

SystemAPI::SystemAPI(void)
{
	// Empty
}

void SystemAPI::begin(void){
	// release all buttons
	end();
}

void SystemAPI::end(void){
	uint8_t _report = 0;
	SendReport(&_report, sizeof(_report));
}

void SystemAPI::write(uint8_t s){
	press(s);
	release();
}

void SystemAPI::release(void){
	begin();
}

void SystemAPI::releaseAll(void){
	begin();
}

void SystemAPI::press(uint8_t s){
#ifdef USBCON
	if (s == SYSTEM_WAKE_UP)
		USBDevice.wakeupHost();
	else
#endif
		SendReport(&s, sizeof(s));
}

