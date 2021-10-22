#pragma once
#include "pch.h"
#include "Queue.h"
#include "Applicant.h"

/*
 * ќчередь на улучшение жилищных условий имеет название, хранит им€ бинарного
 * файла дл€ данных. 
 *
 * «апись в файл реализовать при помощи итератора.
 * –еализовать дополнительно операции (при помощи итераторов):
 *     Х ѕоиск в очереди по фамилии Ц находим первую подход€щую фамилию,
 *       остальных однофамильцев игнорировать
 *     Х ќбъединение двух очередей в новую очередь, при этом файлы исходных
 *       очередей удал€ютс€. ќчередников, наход€щихс€ в обеих очеред€х включать
 *       в итоговую очередь только один раз. ћетод merge(fileNameSecond), им€
 *       результирующего файла формировать по правилу:
 *       merge_им€‘айла1_им€‘айла2.bin,
 *       им€ очереди ќбъединение Ђочередь1ї и Ђочередь2ї.
 *
 */
class ApplicantQueue
{
public:
	static const int N_FILE_NAME = 255, N_QUEUE_NAME = 101;

private:
	char* fileName_;                   // им€ файла данных
	char* queueName_;                  // им€ очереди
	Queue<Applicant> applicantQueue_;  // очередь на улучщение жилищных условий

public:
	ApplicantQueue():ApplicantQueue("file.bin", "очередь 1", Queue<Applicant>()) {  }

	ApplicantQueue(const char* fileName):ApplicantQueue(
		fileName, "ќчередь 1", Queue<Applicant>())
	{  }

	// т.к. это создание объекта, то при наличии данных в переданной очереди
	// просто сохраним данные из очереди в указанном файле
	// если данных в очереди нет
	ApplicantQueue(const char* fileName, const char* queueName, const Queue<Applicant>& applicantQueue)
		: fileName_(new char[N_FILE_NAME] {0}),
		  queueName_(new char[N_QUEUE_NAME] {0}),
		  applicantQueue_(applicantQueue)
	{
		// установить им€ файла и им€ очереди
		setFileName(fileName);
		setQueueName(queueName);

		// задать данные очереди
		applicantQueue_ = applicantQueue;

		// сохранить данные очереди в файле
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

	// ѕоиск в очереди по фамилии
	Applicant find(const char* surname);

	bool contains(const Applicant& applicant);
	
	// ќбъединение двух очередей
	ApplicantQueue& merge(char* fileName);

	// вывод
	friend ostream& operator<<(ostream& os, const ApplicantQueue& applicant) {

		os << "\n\t »м€ очереди : "
			<< applicant.queueName_
			<< "\n\t »м€ бинарного файла : "
			<< applicant.fileName_
			<< Applicant::showHeader << applicant.applicantQueue_ << Applicant::showFooter;
	
		return os;
	}




};

