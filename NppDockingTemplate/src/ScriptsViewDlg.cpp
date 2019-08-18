//this file is part of notepad++
//Copyright (C)2003 Don HO ( donho@altern.org )
//
//This program is free software; you can redistribute it and/or
//modify it under the terms of the GNU General Public License
//as published by the Free Software Foundation; either
//version 2 of the License, or (at your option) any later version.
//
//This program is distributed in the hope that it will be useful,
//but WITHOUT ANY WARRANTY; without even the implied warranty of
//MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//GNU General Public License for more details.
//
//You should have received a copy of the GNU General Public License
//along with this program; if not, write to the Free Software
//Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.
#include "stdafx.h"
#include "NppDockingTemplate/include/ScriptsViewDlg.h"

extern NppData nppData;

INT_PTR CALLBACK ScriptsViewDlg::run_dlgProc(UINT message, WPARAM wParam, LPARAM lParam)
{
	switch (message) 
	{
		case WM_COMMAND : 
		{
			switch (wParam)
			{
				case IDOK :
				{
					return FALSE;
				}
			}
				return FALSE;
		}

		default :
			return DockingDlgInterface::run_dlgProc(message, wParam, lParam);
	}
}

void ScriptsViewDlg::display(bool toShow /*= true*/) const 
{
	DockingDlgInterface::display(toShow);
	if (toShow)
		::SetFocus(::GetDlgItem(_hSelf, ID_GOLINE_EDIT));
}

void ScriptsViewDlg::setParent(HWND parent2set)
{
	_hParent = parent2set;
};