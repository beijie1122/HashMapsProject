#include "MyMap.h"

int MyMap::GetBucketIndex(std::string key)
{
	int HashCode = 0;

	int Base = 1;

	int PrimeNum = 37;

	for (size_t i = key.size() - 1; i >= 0; i--)
	{
		HashCode += key[i] * Base;
		Base = Base * PrimeNum;

		HashCode = HashCode % NumBuckets;
		Base = Base % NumBuckets;
	}

	return HashCode % NumBuckets;
}

void MyMap::Rehash()
{
	Node** Temp = buckets;
	buckets = new Node* [2 * NumBuckets];
	for (size_t i = 0; i < 2 * NumBuckets; i++)
	{
		buckets[i] = NULL;
	}
	int OldBucketSize = NumBuckets;
	NumBuckets *= 2;
	Count = 0;

	for (size_t i = 0; i < OldBucketSize; i++)
	{
		Node* head = Temp[i];

		while (head != NULL)
		{
			std::string Key = head->Key;
			int Value = head->Value;
			Insert(Key, Value);
			head = head->next;
		}
	}

	for (size_t i = 0; i < OldBucketSize; i++)
	{
		delete Temp[i];
	}

	delete []Temp;

}

int MyMap::size()
{
	return Count;
}

int MyMap::GetValue(std::string key)
{
	int BucketIndex = GetBucketIndex(key);
	Node* head = buckets[BucketIndex];

	while (head != NULL)
	{
		if (head->Key == key)
		{
			return head->Value;
		}
		head = head->next;
	}

	return -1;
}

void MyMap::Insert(std::string key, int value)
{
	int BucketIndex = GetBucketIndex(key);
	Node* head = buckets[BucketIndex];
	while (head != NULL)
	{
		if (head->Key == key)
		{
			head->Value = value;
			return;
		}
		head = head->next;
	}

	Node* node = new Node(key, value);
	node->next = buckets[BucketIndex];
	buckets[BucketIndex] = node;

	Count++;

	double LoadFactor = (1.0 * Count) / NumBuckets;

	if (LoadFactor > 0.7)
	{
		std::cout << "Rehashing Done!\n";
		Rehash();
	}

}

int MyMap::Remove(std::string key)
{
	int bucketIndex = GetBucketIndex(key);
	Node* head = buckets[bucketIndex];
	Node* PrevPointer = NULL;

	while (head != NULL)
	{
		if (head->Key == key)
		{
			if (PrevPointer == NULL)
			{
				buckets[bucketIndex] = head->next;
			}
			else
			{
				PrevPointer->next = head->next;
				
				
			}
			int Value = head->Value;
			head->next = NULL;
			delete head;
			Count--;
			return Value;
		}
		PrevPointer = head;
		head = head->next;

	}

	return 0;

}

double MyMap::GetLoadFactor()
{
	return (1.0*Count)/NumBuckets;
}

MyMap::MyMap()
{
	Count = 0;
	NumBuckets = 5;
	buckets = new Node* [NumBuckets];
	for (size_t i = 0; i < NumBuckets; i++)
	{
		buckets[i] = NULL;
	}

}

MyMap::~MyMap()
{
	for (size_t i = 0; i < NumBuckets; i++)
	{
		delete buckets[i];
	}
	delete []buckets;
}
