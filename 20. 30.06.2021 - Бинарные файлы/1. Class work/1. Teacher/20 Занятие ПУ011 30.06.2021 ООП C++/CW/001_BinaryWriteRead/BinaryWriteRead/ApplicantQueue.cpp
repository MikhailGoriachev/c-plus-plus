#include "pch.h"
#include "Applicant.h"
#include "ApplicantQueue.h"

// копирующий конструктор
ApplicantQueue::ApplicantQueue(const ApplicantQueue& applicantQueue):
    fileName_(new char[N_FILE_NAME] {0}),
    queueName_(new char[N_QUEUE_NAME] {0}),
    applicantQueue_(applicantQueue.applicantQueue_)
{
	strcpy(fileName_, applicantQueue.fileName_);
	strcpy(queueName_, applicantQueue.queueName_);
} // ApplicantQueue::ApplicantQueue


// сеттер дл€ имени файла
void ApplicantQueue::setFileName(const char* fileName)
{
	memset(fileName_, 0, N_FILE_NAME);
	strncpy(fileName_, fileName, N_FILE_NAME - 1);
} // ApplicantQueue::setFileName


// сеттер дл€ имени очереди
void ApplicantQueue::setQueueName(const char* queueName)
{
	memset(queueName_, 0, N_QUEUE_NAME);
	strncpy(queueName_, queueName, N_QUEUE_NAME - 1);
} // ApplicantQueue::setQueueName


// ѕоиск в очереди по фамилии
Applicant ApplicantQueue::find(const char* surname)
{
	Queue<Applicant>::Iterator<Applicant> iterator(applicantQueue_);
	for (iterator.begin(); !iterator.end(); ++iterator) {
		if (strcmp((*iterator).getSurname(), surname) == 0) return *iterator;
	} // for itearator

	return Applicant("ѕретендент", "не", "найден", 1, 999., 999, Date(1, 1,1 ));
} // ApplicantQueue::find


// возвращает true если дубликат объекта applicant есть в очереди 
bool ApplicantQueue::contains(const Applicant& applicant)
{
	Queue<Applicant>::Iterator<Applicant> iterator(applicantQueue_);
	for (iterator.begin(); !iterator.end(); ++iterator) {
		if (*iterator == applicant) return true;
	} // for itearator

	return false;
} // ApplicantQueue::contains


// ќбъединение двух очередей
// ќбъединение двух очередей в новую очередь, при этом файлы исходных очередей удал€ютс€.
// ќчередников, наход€щихс€ в обеих очеред€х включать в итоговую очередь только один раз.
// ћетод merge(fileNameSecond), им€ результирующего файла формировать по правилу:
//     merge_им€‘айла1_им€‘айла2.bin,
// им€ очереди 'ќбъединение Ђочередь1ї и Ђочередь2ї'.
ApplicantQueue& ApplicantQueue::merge(char* fileName)
{
	char* queueName = new char[N_QUEUE_NAME];

	// формирование нового имени файла и нового имени очереди
	// merge_им€‘айла1_им€‘айла2.bin
	char* newFileName = new char[N_FILE_NAME] {"merge_"};
	strncat(newFileName, fileName_, strlen(fileName_)-4);
	strcat(newFileName, "_");
	strncat(newFileName, fileName, strlen(fileName) - 4);
	strcat(newFileName, ".bin");

	// —оздать новое им€ очереди
	// ќбъединение Ђочередь1ї и Ђочередь2ї.
	char* newQueueName = new char[N_QUEUE_NAME] {"ќбъединение \""};
	strcat(newQueueName, queueName_);
	strcat(newQueueName, "\" и \"");
	strcat(newQueueName, queueName);
	strcat(newQueueName, "\"");
	
	// сохранить новое им€ файла в поле класса
	strcpy(fileName_, newFileName);

	// освобождение пам€ти
	delete[] newFileName;
	delete[] newQueueName;

	return *this;
} // ApplicantQueue::merge
