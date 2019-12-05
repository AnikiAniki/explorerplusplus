// Copyright (C) Explorer++ Project
// SPDX-License-Identifier: GPL-3.0-only
// See LICENSE in the top level directory

#include "stdafx.h"
#include "HistoryEntry.h"

int HistoryEntry::idCounter = 0;

HistoryEntry::HistoryEntry(PCIDLIST_ABSOLUTE pidl, std::wstring_view displayName,
	std::optional<int> systemIconIndex) :
	m_id(idCounter++),
	m_pidl(unique_pidl_absolute(ILCloneFull(pidl))),
	m_displayName(displayName),
	m_systemIconIndex(systemIconIndex)
{

}

int HistoryEntry::GetId() const
{
	return m_id;
}

unique_pidl_absolute HistoryEntry::GetPidl() const
{
	return unique_pidl_absolute(ILCloneFull(m_pidl.get()));
}

std::wstring HistoryEntry::GetDisplayName() const
{
	return m_displayName;
}

std::optional<int> HistoryEntry::GetSystemIconIndex() const
{
	return m_systemIconIndex;
}

void HistoryEntry::SetSystemIconIndex(int iconIndex)
{
	m_systemIconIndex = iconIndex;
}