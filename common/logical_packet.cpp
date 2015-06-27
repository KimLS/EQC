#include <string.h>

#include "logical_packet.h"

LogicalPacket::LogicalPacket(const uint16 opcode, const int size) {
	buffer = new char[size + 2];
	this->size = size;
	*(uint16*)buffer = opcode;
}

LogicalPacket::~LogicalPacket() {
	safe_delete_array(buffer);
}

LogicalPacket::LogicalPacket(const LogicalPacket &r) {
	buffer = new char[r.size + 2];
	size = r.size;
	memcpy(buffer, r.buffer, size + 2);
}

LogicalPacket& LogicalPacket::operator=(const LogicalPacket &r) {
	buffer = new char[r.size + 2];
	size = r.size;
	memcpy(buffer, r.buffer, size + 2);
	return *this;
}
