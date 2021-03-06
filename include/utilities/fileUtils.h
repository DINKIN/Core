/****************************************************************************
 *
 * 		fileUtils.h: File Utilities api
 *      This is part of the yafray package
 *      Copyright (C) 2016  David Bluecame
 *
 *      This library is free software; you can redistribute it and/or
 *      modify it under the terms of the GNU Lesser General Public
 *      License as published by the Free Software Foundation; either
 *      version 2.1 of the License, or (at your option) any later version.
 *
 *      This library is distributed in the hope that it will be useful,
 *      but WITHOUT ANY WARRANTY; without even the implied warranty of
 *      MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 *      Lesser General Public License for more details.
 *
 *      You should have received a copy of the GNU Lesser General Public
 *      License along with this library; if not, write to the Free Software
 *      Foundation,Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307 USA
 *
 */

#ifndef Y_FILEUTILS_H
#define Y_FILEUTILS_H

#include<yafray_config.h>

#include <cstdio>
#include <locale>
#include <utilities/stringUtils.h>

#include <boost/filesystem.hpp>

__BEGIN_YAFRAY

FILE * fileUnicodeOpen(const std::string &filename, const std::string &fileaccess)
{
	FILE * filepointer = nullptr;
	
#if defined(_WIN32)
	std::wstring wfilename = utf8_to_wutf16(filename);
	std::wstringstream wfileaccess;
	wfileaccess << fileaccess.c_str();
	filepointer = _wfopen(wfilename.c_str(), wfileaccess.str().c_str());	//Windows needs the path in UTF16 (unicode) so we have to convert the UTF8 path to UTF16
#else
	filepointer = fopen(filename.c_str(), fileaccess.c_str());
#endif
	return filepointer;
}

int fileUnicodeClose(FILE * filepointer)
{
	return fclose(filepointer);
}


__END_YAFRAY

#endif
