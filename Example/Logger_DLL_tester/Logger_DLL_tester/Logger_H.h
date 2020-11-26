#include <string>
#pragma once
namespace std {
	class LOGGER {
	public:
		static enum LEVEL {
			DEBUG, //Lowest level log type
			INFO,
			WARNING, //Medium level log type
			CRITICAL,
			FATAL, //Highest level log type
			ALL_xREAD_ONLY
		};
		static __declspec(dllexport) bool WRITE(string log, LEVEL level);

		static __declspec(dllexport) string READ(LEVEL level);

	};

	class EXPORT {
	public:
		static __declspec(dllexport) bool TO_FILE(LOGGER::LEVEL level, //log level that will be exported
			string path //Path C:\\blah\blah\blah\blah
		);
	};
}