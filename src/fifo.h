/**
 * @version 1.0
 * @author edcer@sumarte.com
 * @date 9/19/16
 */

#ifndef __FIFO_H__
#define __FIFO_H__

#include <stdint.h>
#include <string.h>
#include <stdbool.h>

/**
 * The first in first out buffer structure.
 */
typedef struct __fifo_t
{
	uint32_t first;						/**< The index of the first data. */
	uint32_t last;						/**< The index of the last data. */
	uint16_t size;						/**< The size of the FIFO. */
	uint8_t* buffer;					/**< The buffer of the FIFO. */

} fifo_t;

/**
* Initialize the FIFO with the given sized buffer.
*
* @param fifo the FIFO structure.
* @param buffer the memory space of the FIFO.
* @param size the size of the FIFO.
*/
void fifo_init(fifo_t* fifo, uint8_t* buffer, uint16_t size);

/**
* Get the count of the FIFO.
*/
uint32_t fifo_get_count(fifo_t* fifo);
/**
* Get the free space of the FIFO.
*/
static inline uint32_t fifo_get_free_space(fifo_t* fifo)
{
	return (fifo->size - 1 - fifo_get_count(fifo));
}

/**
* Delete the the length of the data from the given FIFO
*
* @param fifo, the FIFO pointer.
* @param length, the delete length.
*/
static inline void fifo_clear(fifo_t* fifo)
{
	/* Initialize the FIFO member. */
	fifo->first = 0;
	fifo->last = 0;

	/* Clear the buffer. */
	memset(fifo->buffer, 0, fifo->size);
}

/**
* Write the given data to the FIFO.
*
* @param fifo, the FIFO pointer.
* @param data, the data will be written.
* @param length, the length of the data.
* @return TRUE, is successful.FALSE, is failure.
*/
bool fifo_write(fifo_t* fifo, const void* data, uint32_t length);

/**
* Read the the length of the data from the given FIFO
*
* @param fifo, the FIFO pointer.
* @param data, the buffer of where the read data be saved.
* @return TRUE, is successful.FALSE, is failure.
*/
bool fifo_read(fifo_t* fifo, void* data, uint32_t length);

/**
* Peek the the length of the data from the given FIFO.
*
* @param fifo, the FIFO pointer.
* @param data, the buffer of where the read data be saved.
* @return TRUE, is successful.FALSE, is failure.
*/
bool fifo_peek(fifo_t* fifo, void* data, uint32_t length);



/**
* Delete the fifo data.
*
* @param fifo, the FIFO pointer.
* @param data, the buffer of where the read data be saved.
* @return TRUE, is successful.FALSE, is failure.
*/
bool fifo_delete(fifo_t* fifo, uint32_t length);


#endif /* __FifoEx_H__ */
