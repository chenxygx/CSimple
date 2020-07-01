/**
* @Author: QiuTong
* @Date:2020.06.30
* @Version:v1.0.0
* @Description
*	人员实体
*/
#pragma once
class PersonManager
{
public:
	/*添加*/
	virtual void Add() = 0; 
	/*展示*/
	virtual void Show() = 0;
	/*搜索*/
	virtual void Search() = 0;
	/*更新*/
	virtual void Update() = 0;
	/*删除*/
	virtual void Delete() = 0;
	/*统计*/
	virtual void Total() = 0;
	/*持久化*/
	virtual void Save() = 0;
	/*获取文件内容*/
	virtual void Read() = 0;
};

