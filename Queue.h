#ifndef QUEUE_H
#define QUEUE_H

enum QueueType { FIFO, LIFO };

class ProductQueue
{
	private:
		QueueType qType;
		
	public:
		push( Product* p);
		pop( Product* p);
		QueueType getQueueType();
};

class ProductQueueFIFO : public ProductQueue
{
	private:
		std::list<Product*> products;		//bo K�eczek m�wi�, �e ze stack i queue s� problemy, a z list� nie ma
		//std::queue<Product*> products;
	public:
		void push( Product* p);
		void pop( Product* p);
		//QueueType getQueueType();
};

class ProductQueueLIFO : public ProductQueue
{
	private:
		std::list<Product*> products;
		//std::stack<Product* p> products;	
	
	public:
		void push( Product* p);
		void pop( Product* p);
		//QueueType getQueueType();
};
#endif
