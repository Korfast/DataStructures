#ifndef RINGBUFFER_H
#define RINGBUFFER_H

//! \brief Cтруктура кольцевой буфер.
struct RingBuffer
{
private:
	//! \brief Массив кольцевого буфера.
	int* _array;

	//! \brief Индекс конца кольцевого буфера.
	int _tailIndex = -1;

	//! \brief Индекс начала кольцевого буфера.
	int _headIndex = -1;

	//! \brief Вместимость кольцевого буфера.
	int _capacity;

	//! \brief Размер кольцевого буфера.
	int _size = 0;

public:
	//! \brief Создает структуру кольцевой буфер.
	RingBuffer();

	RingBuffer(int cap);

	//! \brief Освобождает память.
	~RingBuffer();

	//! \brief Добавляет данные в кольцевой буфер.
	//! \param data Данные.
	void AddElement(int data);

	//! \brief Достает первый элемент из кольцевого буфера. 
	//! После чего удаляет этот элемент из буфера.
	//! \return Значение первого элемента.
	int GetElement();

	//! \brief Увеличивает размер массива кольцевого буфера.
	void Resize();

	//! \brief Очищает кольцевой буфер.
	void ClearRingBuf();

	//! \brief Возвращает массив кольцевого буфера,
	//! где первый элемент находится под индексом _headIndex,
	//! а последний под индексом _tailIndex.
	//! \return Массив кольцевого буфера.
	int* GetArray();

	//! \brief Возвращает вместимость кольцевого буфера.
	//! \return Вместимость.
	int GetCapacity() const;

	//! \brief Возвращает значение свободного места в кольцевом буфере.
	//! \return Количество свободного места в кольцевом буфере.
	int GetFreeSpace() const;

	//! \brief Возвращает количество элементов в кольцевом буфере.
	//! \return Количество элементов в кольцевом буфере.
	int GetSize() const;

	bool IsEmpty() const; // <-- Добавлен
	bool IsFull() const;  // <-- Добавлен
};

#endif // RINGBUFFER_H