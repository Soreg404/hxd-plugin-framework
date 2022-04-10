#pragma once

#include <algorithm> 
#include <cwctype>
#include <string>

// trim from start (in place)
inline void ltrim(std::wstring &s) {
	s.erase(
		s.begin(),
		std::find_if(s.begin(), s.end(),
			[](int ch) { return !std::iswspace(ch); }
		)
	);
}

// trim from end (in place)
inline void rtrim(std::wstring &s) {
	s. erase(
		std::find_if(s.rbegin(), s.rend(),
			[](int ch) { return !std::iswspace(ch); }
		).base(),
		s.end()
	);
}

// trim from both ends (in place)
inline void trim(std::wstring &s) { ltrim(s); rtrim(s); }

// trim from start (copying)
inline std::wstring ltrim_copy(std::wstring s) { ltrim(s); return s; }

// trim from end (copying)
inline std::wstring rtrim_copy(std::wstring s) { rtrim(s); return s; }

// trim from both ends (copying)
inline std::wstring trim_copy(std::wstring s) { trim(s); return s; }
