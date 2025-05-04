/**
 * Copyright (c) 2016, Sumarte Technology, All right reserved
 *
 * @file FifoEx.h
 * The first in first out buffer.
 *
 * @version 1.0
 * @author edcer@sumarte.com
 * @date 9/19/16
 */

#include "fifo.h"


/**
 * Get the count of the FIFO.
 */
uint32_t fifo_get_count(fifo_t *fifo)
{
    volatile uint32_t ffirst = fifo->first;
    volatile uint32_t flast = fifo->last;

    if (ffirst >= flast)
    {
        return ffirst - flast;
    }
    else
    {
        return (fifo->size + ffirst - flast);
    }
}

/**
 * Initialize the FIFO with the given sized buffer.
 *
 * @param fifo the FIFO structure.
 * @param buffer the memory space of the FIFO.
 * @param size the size of the FIFO.
 */
void fifo_init(fifo_t *fifo, uint8_t *buffer, uint16_t size)
{
    /* Initialize the FIFO member. */
    fifo->buffer = buffer;
    fifo->size = size;
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
 * @return TRUE, is success. FALSE, is failure.
 */
bool fifo_write(fifo_t *fifo, const void *data, uint32_t length)
{
    int first = 0;
    int offset = 0;

    /* Fix the given length. */
    if (fifo_get_free_space(fifo) < length)
    {
        return false;
    }

    /* Calcaluate the offset. */
    first = fifo->first + length;

    /* If the new first is less than size. */
    if (first <= fifo->size)
    {
        /* Save the data. */
        memcpy(fifo->buffer + fifo->first, data, length);
    }
    else
    {
        /* calculate the data offset. */
        offset = fifo->size - fifo->first;

        /* Save the data. */
        memcpy(((fifo->buffer) + (fifo->first)), data, offset);
        memcpy(fifo->buffer, ((uint8_t *)data + offset), length - offset);
    }

    /* fix the first */
    fifo->first = first < fifo->size ? first : first - fifo->size;

    return true;
}

/**
 * Read the the length of the data from the given FIFO
 *
 * @param fifo, the FIFO pointer.
 * @param data, the buffer of where the read data be saved.
 * @return TRUE, is success. FALSE, is failure.
 */
bool fifo_read(fifo_t *fifo, void *data, uint32_t length)
{
    int last = 0;
    int offset = 0;

    /* Fix the given length. */
    if (fifo_get_count(fifo) < length)
    {
        return false;
    }

    last = fifo->last + length;

    if (last <= fifo->size)
    {
        /* Save the data. */
        memcpy(data, ((fifo->buffer) + (fifo->last)), length);
    }
    else
    {
        /* calculate the data offset. */
        offset = fifo->size - fifo->last;

        /* Save the data. */
        memcpy(data, ((fifo->buffer) + (fifo->last)), offset);
        memcpy((((uint8_t *)data) + offset), (fifo->buffer), length - offset);
    }

    /* Update the first index. */
    fifo->last += length;

    /* Fix the last index. */
    fifo->last %= fifo->size;

    return true;
}

/**
 * Peek the the length of the data from the given FIFO.
 *
 * @param fifo, the FIFO pointer.
 * @param data, the buffer of where the read data be saved.
 * @return TRUE, is success. FALSE, is failure.
 */
bool fifo_peek(fifo_t *fifo, void *data, uint32_t length)
{
    int last = 0;
    int offset = 0;

    /* Fix the given length. */
    if (fifo_get_count(fifo) < length)
    {
        return false;
    }

    last = fifo->last + length;

    if (last <= fifo->size)
    {
        /* Save the data. */
        memcpy(data, ((fifo->buffer) + (fifo->last)), length);
    }
    else
    {
        /* calculate the data offset. */
        offset = fifo->size - fifo->last;

        /* Save the data. */
        memcpy(data, ((fifo->buffer) + (fifo->last)), offset);
        memcpy((((uint8_t *)data) + offset), (fifo->buffer), length - offset);
    }

    return true;
}

/**
 * Delete the fifo data.
 *
 * @param fifo, the FIFO pointer.
 * @param data, the buffer of where the read data be saved.
 * @return TRUE, is success. FALSE, is failure.
 */
bool fifo_delete(fifo_t *fifo, uint32_t length)
{
    int end;

    /* Fix the given length. */
    if (fifo_get_count(fifo) < length)
    {
        return false;
    }

    /* Update the first index. */
    end = fifo->last + length;

    /* Fix the last index. */
    fifo->last = end < fifo->size ? end : (end - fifo->size);

    return true;
}
