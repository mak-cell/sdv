# 05 DMA (side question, 2026-10-07)
DMA = Direct Memory Access: a helper in the chip that copies between peripherals and RAM without the CPU.

Without DMA: one interrupt per UART byte, CPU copies each one.
With DMA: CPU sets source, destination and count once; DMA moves the data; one interrupt when done.

Used for: UART/SPI receive, ADC sampling, audio, Ethernet, big memory copies.

Link to volatile: DMA writes the buffer, your code doesn't, so mark the buffer/flag `volatile`. On Cortex-M7 with cache, also clean/invalidate the cache.

Interview: "DMA moves data between peripherals and memory without the CPU, cutting interrupt load. The CPU configures source, destination and length, and gets one interrupt at the end."
