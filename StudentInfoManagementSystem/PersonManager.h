/**
* @Author: QiuTong
* @Date:2020.06.30
* @Version:v1.0.0
* @Description
*	��Աʵ��
*/
#pragma once
class PersonManager
{
public:
	/*���*/
	virtual void Add() = 0; 
	/*չʾ*/
	virtual void Show() = 0;
	/*����*/
	virtual void Search() = 0;
	/*����*/
	virtual void Update() = 0;
	/*ɾ��*/
	virtual void Delete() = 0;
	/*ͳ��*/
	virtual void Total() = 0;
	/*�־û�*/
	virtual void Save() = 0;
	/*��ȡ�ļ�����*/
	virtual void Read() = 0;
};

