#include "pch.h"
#include <iostream>
#include <thread>
#include <future>
#include <string>
#include <atomic>
#include <mutex>
#include <fstream>
using namespace std;
mutex mtx;
struct LOG_ {
	string ID;
	string content;
	LOG_(string id, string cont) {
		ID = id;
		content = cont;
	}
};
LOG_* DEBUG_LOG[500000];
LOG_* INFO_LOG[500000];
LOG_* WARNING_LOG[500000];
LOG_* CRITICAL_LOG[500000];
LOG_* FATAL_LOG[500000];
int incremental_num[5] = { 0, 0, 0, 0, 0 }; //Number that increments for progressive logging and array positions

void WRITE_LOG(string type, int inc, string content) {
	//cout << "Writing: " << type << "_" << incremental_num[inc] << ": " << content << endl;
	if (type == "DEBUG") {
		mtx.lock();
		DEBUG_LOG[incremental_num[inc]] = new LOG_((type + "_" + to_string(incremental_num[inc])), content);
		mtx.unlock();
	}
	if (type == "INFO") {
		mtx.lock();
		INFO_LOG[incremental_num[inc]] = new LOG_((type + "_" + to_string(incremental_num[inc])), content);
		mtx.unlock();
	}
	else if (type == "WARNING") {
		mtx.lock();
		WARNING_LOG[incremental_num[inc]] = new LOG_((type + "_" + to_string(incremental_num[inc])), content);
		mtx.unlock();
	}
	else if (type == "CRITICAL") {
		mtx.lock();
		CRITICAL_LOG[incremental_num[inc]] = new LOG_((type + "_" + to_string(incremental_num[inc])), content);
		mtx.unlock();
	}
	else if (type == "FATAL") {
		mtx.lock();
		FATAL_LOG[incremental_num[inc]] = new LOG_((type + "_" + to_string(incremental_num[inc])), content);
		mtx.unlock();
	}
};

string READ_LOG(string type) {	
	//cout << "READING: " << type << endl;
	if (type == "DEBUG") {
		string placeholder = "";
		for (int i = 0; i < incremental_num[0]; i++) {
			mtx.lock();
			placeholder = placeholder + DEBUG_LOG[i]->ID + ": " + DEBUG_LOG[i]->content + "\n";
			mtx.unlock();
		}
		return placeholder;
	}

	if (type == "INFO") {
		string placeholder = "";
		for (int i = 0; i < incremental_num[1]; i++) {
			mtx.lock();
			placeholder = placeholder + INFO_LOG[i]->ID + ": " + INFO_LOG[i]->content + "\n";
			mtx.unlock();
		}
		return placeholder;
	}

	else if (type == "WARNING") {
		string placeholder;
		for (int i = 0; i < incremental_num[2]; i++) {
			mtx.lock();
			placeholder = placeholder + WARNING_LOG[i]->ID + ": " + WARNING_LOG[i]->content + "\n";
			mtx.unlock();
		}
		return placeholder;
	}

	else if (type == "CRITICAL") {
		string placeholder;
		for (int i = 0; i < incremental_num[3]; i++) {
			mtx.lock();
			placeholder = placeholder + CRITICAL_LOG[i]->ID + ": " + CRITICAL_LOG[i]->content + "\n";
			mtx.unlock();
		}
		return placeholder;
	}

	else if (type == "FATAL") {
		string placeholder;
		for (int i = 0; i < incremental_num[4]; i++) {
			mtx.lock();
			placeholder = placeholder + FATAL_LOG[i]->ID + ": " + FATAL_LOG[i]->content + "\n";
			mtx.unlock();
		}
		return placeholder;
	}

	else if (type == "ALL") {
		string placeholder = "";
		for (int i = 0; i < incremental_num[0]; i++) {
			mtx.lock();
			placeholder = placeholder + DEBUG_LOG[i]->ID + ": " + DEBUG_LOG[i]->content + "\n";
			mtx.unlock();
		}
		for (int i = 0; i < incremental_num[1]; i++) {
			mtx.lock();
			placeholder = placeholder + INFO_LOG[i]->ID + ": " + INFO_LOG[i]->content + "\n";
			mtx.unlock();
		}
		for (int i = 0; i < incremental_num[2]; i++) {
			mtx.lock();
			placeholder = placeholder + WARNING_LOG[i]->ID + ": " + WARNING_LOG[i]->content + "\n";
			mtx.unlock();
		}
		for (int i = 0; i < incremental_num[3]; i++) {
			mtx.lock();
			placeholder = placeholder + CRITICAL_LOG[i]->ID + ": " + CRITICAL_LOG[i]->content + "\n";
			mtx.unlock();
		}
		for (int i = 0; i < incremental_num[4]; i++) {
			mtx.lock();
			placeholder = placeholder + FATAL_LOG[i]->ID + ": " + FATAL_LOG[i]->content + "\n";
			mtx.unlock();
		}
		return placeholder;
	}
};

bool FILE_WRITER(string type, string path) {
	if (type == "DEBUG") {
		string placeholder;
		for (int i = 0; i < incremental_num[0]; i++) {
			mtx.lock();
			placeholder = placeholder + DEBUG_LOG[i]->ID + ": " + DEBUG_LOG[i]->content + "\n";
			mtx.unlock();
		}
		ofstream FILE;
		FILE.open(path);
		FILE << placeholder;
		FILE.close();
		return true;
	}
	else if (type == "INFO") {
		string placeholder;
		for (int i = 0; i < incremental_num[1]; i++) {
			mtx.lock();
			placeholder = placeholder + INFO_LOG[i]->ID + ": " + INFO_LOG[i]->content + "\n";
			mtx.unlock();
		}
		ofstream FILE;
		FILE.open(path);
		FILE << placeholder;
		FILE.close();
		return true;
	}
	else if (type == "WARNING") {
		string placeholder;
		for (int i = 0; i < incremental_num[2]; i++) {
			mtx.lock();
			placeholder = placeholder + WARNING_LOG[i]->ID + ": " + WARNING_LOG[i]->content + "\n";
			mtx.unlock();
		}
		ofstream FILE;
		FILE.open(path);
		FILE << placeholder;
		FILE.close();
		return true;
	}
	else if (type == "CRITICAL") {
		string placeholder;
		for (int i = 0; i < incremental_num[3]; i++) {
			mtx.lock();
			placeholder = placeholder + CRITICAL_LOG[i]->ID + ": " + CRITICAL_LOG[i]->content + "\n";
			mtx.unlock();
		}
		ofstream FILE;
		FILE.open(path);
		FILE << placeholder;
		FILE.close();
		return true;
	}
	else if (type == "FATAL") {
		string placeholder;
		for (int i = 0; i < incremental_num[4]; i++) {
			mtx.lock();
			placeholder = placeholder + FATAL_LOG[i]->ID + ": " + FATAL_LOG[i]->content + "\n";
			mtx.unlock();
		}
		ofstream FILE;
		FILE.open(path);
		FILE << placeholder;
		FILE.close();
		return true;
	}
	else if (type == "ALL") {
		string placeholder;
		for (int i = 0; i < incremental_num[0]; i++) {
			mtx.lock();
			placeholder = placeholder + DEBUG_LOG[i]->ID + ": " + DEBUG_LOG[i]->content + "\n";
			mtx.unlock();
		}
		for (int i = 0; i < incremental_num[1]; i++) {
			mtx.lock();
			placeholder = placeholder + INFO_LOG[i]->ID + ": " + INFO_LOG[i]->content + "\n";
			mtx.unlock();
		}
		for (int i = 0; i < incremental_num[2]; i++) {
			mtx.lock();
			placeholder = placeholder + WARNING_LOG[i]->ID + ": " + WARNING_LOG[i]->content + "\n";
			mtx.unlock();
		}
		for (int i = 0; i < incremental_num[3]; i++) {
			mtx.lock();
			placeholder = placeholder + CRITICAL_LOG[i]->ID + ": " + CRITICAL_LOG[i]->content + "\n";
			mtx.unlock();
		}
		for (int i = 0; i < incremental_num[4]; i++) {
			mtx.lock();
			placeholder = placeholder + FATAL_LOG[i]->ID + ": " + FATAL_LOG[i]->content + "\n";
			mtx.unlock();
		}
		ofstream FILE;
		FILE.open(path);
		FILE << placeholder;
		FILE.close();
		return true;
	}
	else {
		return false;
	}
}


#include "Logger_H.h"
namespace std {
	bool LOGGER::WRITE(string log, LOGGER::LEVEL level) {
		if (level == DEBUG) {
			WRITE_LOG("DEBUG", 0, log);
			incremental_num[0]++;
			return true;
		}
		else if (level == INFO) {
			WRITE_LOG("INFO", 1, log);
			incremental_num[1]++;
			return true;
		}
		else if (level == WARNING) {
			WRITE_LOG("WARNING", 2, log);
			incremental_num[2]++;
			return true;
		}
		else if (level == CRITICAL) {
			WRITE_LOG("CRITICAL", 3, log);
			incremental_num[3]++;
			return true;
		}
		else if (level == FATAL) {
			WRITE_LOG("FATAL", 4, log);
			incremental_num[4]++;
			return true;
		}
		else {
			return false;
		};
	};

	string LOGGER::READ(LOGGER::LEVEL level) {
		if (level == DEBUG) {
			return READ_LOG("DEBUG");
		}
		else if (level == INFO) {
			return READ_LOG("INFO");
		}
		else if (level == WARNING) {
			return READ_LOG("WARNING");
		}
		else if (level == CRITICAL) {
			return READ_LOG("CRITICAL");
		}
		else if (level == FATAL) {
			return READ_LOG("FATAL");
		}
		else if (level == ALL_xREAD_ONLY) {
			return READ_LOG("ALL");
		}
		else {
			return "ERROR";
		}
	};

	bool EXPORT::TO_FILE(LOGGER::LEVEL level, string path) {
		if (level == LOGGER::LEVEL::DEBUG) {
			future<bool> WRITE_FILE = async(FILE_WRITER, "DEBUG", path);
			return WRITE_FILE.get();
		}
		else if (level == LOGGER::LEVEL::INFO) {
			future<bool> WRITE_FILE = async(FILE_WRITER, "INFO", path);
			return WRITE_FILE.get();
		}
		else if (level == LOGGER::LEVEL::WARNING) {
			future<bool> WRITE_FILE = async(FILE_WRITER, "WARNING", path);
			return WRITE_FILE.get();
		}
		else if (level == LOGGER::LEVEL::CRITICAL) {
			future<bool> WRITE_FILE = async(FILE_WRITER, "CRITICAL", path);
			return WRITE_FILE.get();
		}
		else if (level == LOGGER::LEVEL::FATAL) {
			future<bool> WRITE_FILE = async(FILE_WRITER, "FATAL", path);
			return WRITE_FILE.get();
		}
		else if (level == LOGGER::LEVEL::ALL_xREAD_ONLY) {
			future<bool> WRITE_FILE = async(FILE_WRITER, "ALL", path);
			return WRITE_FILE.get();
		}
	}
};