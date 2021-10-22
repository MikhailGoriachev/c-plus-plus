#include "pch.h"
#include "Applicant.h"
#include "ApplicantQueue.h"

// ���������� �����������
ApplicantQueue::ApplicantQueue(const ApplicantQueue& applicantQueue):
    fileName_(new char[N_FILE_NAME] {0}),
    queueName_(new char[N_QUEUE_NAME] {0}),
    applicantQueue_(applicantQueue.applicantQueue_)
{
	strcpy(fileName_, applicantQueue.fileName_);
	strcpy(queueName_, applicantQueue.queueName_);
} // ApplicantQueue::ApplicantQueue


// ������ ��� ����� �����
void ApplicantQueue::setFileName(const char* fileName)
{
	memset(fileName_, 0, N_FILE_NAME);
	strncpy(fileName_, fileName, N_FILE_NAME - 1);
} // ApplicantQueue::setFileName


// ������ ��� ����� �������
void ApplicantQueue::setQueueName(const char* queueName)
{
	memset(queueName_, 0, N_QUEUE_NAME);
	strncpy(queueName_, queueName, N_QUEUE_NAME - 1);
} // ApplicantQueue::setQueueName


// ����� � ������� �� �������
Applicant ApplicantQueue::find(const char* surname)
{
	Queue<Applicant>::Iterator<Applicant> iterator(applicantQueue_);
	for (iterator.begin(); !iterator.end(); ++iterator) {
		if (strcmp((*iterator).getSurname(), surname) == 0) return *iterator;
	} // for itearator

	return Applicant("����������", "��", "������", 1, 999., 999, Date(1, 1,1 ));
} // ApplicantQueue::find


// ���������� true ���� �������� ������� applicant ���� � ������� 
bool ApplicantQueue::contains(const Applicant& applicant)
{
	Queue<Applicant>::Iterator<Applicant> iterator(applicantQueue_);
	for (iterator.begin(); !iterator.end(); ++iterator) {
		if (*iterator == applicant) return true;
	} // for itearator

	return false;
} // ApplicantQueue::contains


// ����������� ���� ��������
// ����������� ���� �������� � ����� �������, ��� ���� ����� �������� �������� ���������.
// �����������, ����������� � ����� �������� �������� � �������� ������� ������ ���� ���.
// ����� merge(fileNameSecond), ��� ��������������� ����� ����������� �� �������:
//     merge_��������1_��������2.bin,
// ��� ������� '����������� ��������1� � ��������2�'.
ApplicantQueue& ApplicantQueue::merge(char* fileName)
{
	char* queueName = new char[N_QUEUE_NAME];

	// ������������ ������ ����� ����� � ������ ����� �������
	// merge_��������1_��������2.bin
	char* newFileName = new char[N_FILE_NAME] {"merge_"};
	strncat(newFileName, fileName_, strlen(fileName_)-4);
	strcat(newFileName, "_");
	strncat(newFileName, fileName, strlen(fileName) - 4);
	strcat(newFileName, ".bin");

	// ������� ����� ��� �������
	// ����������� ��������1� � ��������2�.
	char* newQueueName = new char[N_QUEUE_NAME] {"����������� \""};
	strcat(newQueueName, queueName_);
	strcat(newQueueName, "\" � \"");
	strcat(newQueueName, queueName);
	strcat(newQueueName, "\"");
	
	// ��������� ����� ��� ����� � ���� ������
	strcpy(fileName_, newFileName);

	// ������������ ������
	delete[] newFileName;
	delete[] newQueueName;

	return *this;
} // ApplicantQueue::merge
