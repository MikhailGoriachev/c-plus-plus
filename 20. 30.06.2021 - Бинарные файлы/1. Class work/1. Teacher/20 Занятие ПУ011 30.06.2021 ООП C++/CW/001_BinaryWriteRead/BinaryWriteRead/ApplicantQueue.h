#pragma once
#include "pch.h"
#include "Queue.h"
#include "Applicant.h"

/*
 * ������� �� ��������� �������� ������� ����� ��������, ������ ��� ���������
 * ����� ��� ������. 
 *
 * ������ � ���� ����������� ��� ������ ���������.
 * ����������� ������������� �������� (��� ������ ����������):
 *     � ����� � ������� �� ������� � ������� ������ ���������� �������,
 *       ��������� ������������� ������������
 *     � ����������� ���� �������� � ����� �������, ��� ���� ����� ��������
 *       �������� ���������. �����������, ����������� � ����� �������� ��������
 *       � �������� ������� ������ ���� ���. ����� merge(fileNameSecond), ���
 *       ��������������� ����� ����������� �� �������:
 *       merge_��������1_��������2.bin,
 *       ��� ������� ����������� ��������1� � ��������2�.
 *
 */
class ApplicantQueue
{
public:
	static const int N_FILE_NAME = 255, N_QUEUE_NAME = 101;

private:
	char* fileName_;                   // ��� ����� ������
	char* queueName_;                  // ��� �������
	Queue<Applicant> applicantQueue_;  // ������� �� ��������� �������� �������

public:
	ApplicantQueue():ApplicantQueue("file.bin", "������� 1", Queue<Applicant>()) {  }

	ApplicantQueue(const char* fileName):ApplicantQueue(
		fileName, "������� 1", Queue<Applicant>())
	{  }

	// �.�. ��� �������� �������, �� ��� ������� ������ � ���������� �������
	// ������ �������� ������ �� ������� � ��������� �����
	// ���� ������ � ������� ���
	ApplicantQueue(const char* fileName, const char* queueName, const Queue<Applicant>& applicantQueue)
		: fileName_(new char[N_FILE_NAME] {0}),
		  queueName_(new char[N_QUEUE_NAME] {0}),
		  applicantQueue_(applicantQueue)
	{
		// ���������� ��� ����� � ��� �������
		setFileName(fileName);
		setQueueName(queueName);

		// ������ ������ �������
		applicantQueue_ = applicantQueue;

		// ��������� ������ ������� � �����
	} // ApplicationQueue

	ApplicantQueue(const ApplicantQueue& applicantQueue);

	~ApplicantQueue()
	{
		delete[] fileName_;
		delete[] queueName_;
	} // ~ApplicantQueue

	char* getFileName() const { return fileName_; }
	void setFileName(const char* fileName);
	
	char* getQueueName() const { return queueName_; }
	void setQueueName(const char*  queueName);
	
	Queue<Applicant> getApplicantQueue() const { return  applicantQueue_;  }
	void setApplicantQueue(const Queue<Applicant>& applicantQueue) { applicantQueue_ = applicantQueue; }

	// ����� � ������� �� �������
	Applicant find(const char* surname);

	bool contains(const Applicant& applicant);
	
	// ����������� ���� ��������
	ApplicantQueue& merge(char* fileName);

	// �����
	friend ostream& operator<<(ostream& os, const ApplicantQueue& applicant) {

		os << "\n\t ��� ������� : "
			<< applicant.queueName_
			<< "\n\t ��� ��������� ����� : "
			<< applicant.fileName_
			<< Applicant::showHeader << applicant.applicantQueue_ << Applicant::showFooter;
	
		return os;
	}




};

