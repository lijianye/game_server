#include "Client_Game_Message.h"


MSG_120001::MSG_120001(void){
	reset();
}

void MSG_120001::serialize(Block_Buffer &buffer) const {
	buffer.write_int32(agent_num);
	buffer.write_int32(server_num);
	buffer.write_int64(role_id);
	buffer.write_string(account);
	buffer.write_string(timestamp);
	buffer.write_string(ip);
}

int MSG_120001::deserialize(Block_Buffer &buffer) {
	agent_num = buffer.read_int32();
	server_num = buffer.read_int32();
	role_id = buffer.read_int64();
	account = buffer.read_string();
	timestamp = buffer.read_string();
	ip = buffer.read_string();
	return 0;
}

void MSG_120001::reset(){
	agent_num = 0;
	server_num = 0;
	role_id = 0;
	account.clear();
	timestamp.clear();
	ip.clear();
}

MSG_520001::MSG_520001(void){
	reset();
}

void MSG_520001::serialize(Block_Buffer &buffer) const {
	role_info.serialize(buffer);
}

int MSG_520001::deserialize(Block_Buffer &buffer) {
	role_info.deserialize(buffer);
	return 0;
}

void MSG_520001::reset(){
	role_info.reset();
}

MSG_120002::MSG_120002(void){
	reset();
}

void MSG_120002::serialize(Block_Buffer &buffer) const {
	buffer.write_int32(agent_num);
	buffer.write_int32(server_num);
	buffer.write_uint8(gender);
	buffer.write_string(account);
	buffer.write_string(role_name);
}

int MSG_120002::deserialize(Block_Buffer &buffer) {
	agent_num = buffer.read_int32();
	server_num = buffer.read_int32();
	gender = buffer.read_uint8();
	account = buffer.read_string();
	role_name = buffer.read_string();
	return 0;
}

void MSG_120002::reset(){
	agent_num = 0;
	server_num = 0;
	gender = 0;
	account.clear();
	role_name.clear();
}

MSG_520002::MSG_520002(void){
	reset();
}

void MSG_520002::serialize(Block_Buffer &buffer) const {
	buffer.write_int64(role_id);
}

int MSG_520002::deserialize(Block_Buffer &buffer) {
	role_id = buffer.read_int64();
	return 0;
}

void MSG_520002::reset(){
	role_id = 0;
}

MSG_120100::MSG_120100(void){
	reset();
}

void MSG_120100::serialize(Block_Buffer &buffer) const {
}

int MSG_120100::deserialize(Block_Buffer &buffer) {
	return 0;
}

void MSG_120100::reset(){
}

MSG_120101::MSG_120101(void){
	reset();
}

void MSG_120101::serialize(Block_Buffer &buffer) const {
	buffer.write_int32(item_id);
	buffer.write_int32(item_amount);
}

int MSG_120101::deserialize(Block_Buffer &buffer) {
	item_id = buffer.read_int32();
	item_amount = buffer.read_int32();
	return 0;
}

void MSG_120101::reset(){
	item_id = 0;
	item_amount = 0;
}

MSG_120107::MSG_120107(void){
	reset();
}

void MSG_120107::serialize(Block_Buffer &buffer) const {
	buffer.write_int32(item_id);
	buffer.write_int32(item_amount);
}

int MSG_120107::deserialize(Block_Buffer &buffer) {
	item_id = buffer.read_int32();
	item_amount = buffer.read_int32();
	return 0;
}

void MSG_120107::reset(){
	item_id = 0;
	item_amount = 0;
}

MSG_520100::MSG_520100(void){
	reset();
}

void MSG_520100::serialize(Block_Buffer &buffer) const {
	uint16_t __item_info_vec_vec_size = item_info_vec.size();
	buffer.write_uint16(__item_info_vec_vec_size);
	for(uint16_t i = 0; i < __item_info_vec_vec_size; ++i) {
		item_info_vec[i].serialize(buffer);
	}

}

int MSG_520100::deserialize(Block_Buffer &buffer) {
	uint16_t __item_info_vec_vec_size = buffer.read_uint16();
	Item_Basic_Info v;
	for(uint16_t i = 0; i < __item_info_vec_vec_size; ++i) {
		if(v.deserialize(buffer))
			return -1;
		item_info_vec.push_back(v);
	}

	return 0;
}

void MSG_520100::reset(){
	item_info_vec.clear();
}

MSG_520101::MSG_520101(void){
	reset();
}

void MSG_520101::serialize(Block_Buffer &buffer) const {
}

int MSG_520101::deserialize(Block_Buffer &buffer) {
	return 0;
}

void MSG_520101::reset(){
}

MSG_520102::MSG_520102(void){
	reset();
}

void MSG_520102::serialize(Block_Buffer &buffer) const {
}

int MSG_520102::deserialize(Block_Buffer &buffer) {
	return 0;
}

void MSG_520102::reset(){
}

MSG_120200::MSG_120200(void){
	reset();
}

void MSG_120200::serialize(Block_Buffer &buffer) const {
}

int MSG_120200::deserialize(Block_Buffer &buffer) {
	return 0;
}

void MSG_120200::reset(){
}

MSG_120201::MSG_120201(void){
	reset();
}

void MSG_120201::serialize(Block_Buffer &buffer) const {
	buffer.write_int32(mail_id);
}

int MSG_120201::deserialize(Block_Buffer &buffer) {
	mail_id = buffer.read_int32();
	return 0;
}

void MSG_120201::reset(){
	mail_id = 0;
}

MSG_120202::MSG_120202(void){
	reset();
}

void MSG_120202::serialize(Block_Buffer &buffer) const {
	buffer.write_int32(mail_id);
}

int MSG_120202::deserialize(Block_Buffer &buffer) {
	mail_id = buffer.read_int32();
	return 0;
}

void MSG_120202::reset(){
	mail_id = 0;
}

MSG_120203::MSG_120203(void){
	reset();
}

void MSG_120203::serialize(Block_Buffer &buffer) const {
	buffer.write_string(receiver_name);
	mail_detail.serialize(buffer);
}

int MSG_120203::deserialize(Block_Buffer &buffer) {
	receiver_name = buffer.read_string();
	mail_detail.deserialize(buffer);
	return 0;
}

void MSG_120203::reset(){
	receiver_name.clear();
	mail_detail.reset();
}

MSG_520200::MSG_520200(void){
	reset();
}

void MSG_520200::serialize(Block_Buffer &buffer) const {
	uint16_t __mail_detail_vec_vec_size = mail_detail_vec.size();
	buffer.write_uint16(__mail_detail_vec_vec_size);
	for(uint16_t i = 0; i < __mail_detail_vec_vec_size; ++i) {
		mail_detail_vec[i].serialize(buffer);
	}

}

int MSG_520200::deserialize(Block_Buffer &buffer) {
	uint16_t __mail_detail_vec_vec_size = buffer.read_uint16();
	Mail_Detail v;
	for(uint16_t i = 0; i < __mail_detail_vec_vec_size; ++i) {
		if(v.deserialize(buffer))
			return -1;
		mail_detail_vec.push_back(v);
	}

	return 0;
}

void MSG_520200::reset(){
	mail_detail_vec.clear();
}

MSG_520201::MSG_520201(void){
	reset();
}

void MSG_520201::serialize(Block_Buffer &buffer) const {
	uint16_t mail_id_vec_size = mail_id_vec.size();
	buffer.write_uint16(mail_id_vec_size);
	for(uint16_t i = 0; i < mail_id_vec_size; ++i) {
		buffer.write_int32(mail_id_vec[i]);
	}

}

int MSG_520201::deserialize(Block_Buffer &buffer) {
	uint16_t mail_id_vec_size = buffer.read_uint16();
	for(uint16_t i = 0; i < mail_id_vec_size; ++i) {
		int32_t v = buffer.read_int32();
		mail_id_vec.push_back(v);
	}
	return 0;
}

void MSG_520201::reset(){
	mail_id_vec.clear();
}

MSG_520202::MSG_520202(void){
	reset();
}

void MSG_520202::serialize(Block_Buffer &buffer) const {
	uint16_t mail_id_vec_size = mail_id_vec.size();
	buffer.write_uint16(mail_id_vec_size);
	for(uint16_t i = 0; i < mail_id_vec_size; ++i) {
		buffer.write_int32(mail_id_vec[i]);
	}

}

int MSG_520202::deserialize(Block_Buffer &buffer) {
	uint16_t mail_id_vec_size = buffer.read_uint16();
	for(uint16_t i = 0; i < mail_id_vec_size; ++i) {
		int32_t v = buffer.read_int32();
		mail_id_vec.push_back(v);
	}
	return 0;
}

void MSG_520202::reset(){
	mail_id_vec.clear();
}

MSG_520203::MSG_520203(void){
	reset();
}

void MSG_520203::serialize(Block_Buffer &buffer) const {
}

int MSG_520203::deserialize(Block_Buffer &buffer) {
	return 0;
}

void MSG_520203::reset(){
}
