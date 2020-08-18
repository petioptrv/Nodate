/*
	rcc.cpp - Implementation for RCC functionality.
	
*/


#include <rcc.h>

#include <limits>


// The maximum handles per port or peripheral is determined by the counter type in the item struct.
// If changed, the counter type should be updated both in the type definition and here.
static const uint8_t handle_max = std::numeric_limits<uint8_t>::max();


// Private methods:

// --- PORT HANDLES ---
std::vector<RccPortHandle>* portHandles() {
	RccPortHandle handle;
	static std::vector<RccPortHandle>* portHandlesStatic = new std::vector<RccPortHandle>(6, handle);
	
#ifdef RCC_AHBENR_GPIOAEN
	((*portHandlesStatic))[RCC_PORT_A].exists = true;
	((*portHandlesStatic))[RCC_PORT_A].enable = RCC_AHBENR_GPIOAEN;
#else
	(*portHandlesStatic)[RCC_PORT_A].exists = false;
#endif

#ifdef RCC_AHBENR_GPIOBEN
	(*portHandlesStatic)[RCC_PORT_B].exists = true;
	(*portHandlesStatic)[RCC_PORT_B].enable = RCC_AHBENR_GPIOBEN;
#else
	(*portHandlesStatic)[RCC_PORT_B].exists = false;
#endif

#ifdef RCC_AHBENR_GPIOCEN
	(*portHandlesStatic)[RCC_PORT_C].exists = true;
	(*portHandlesStatic)[RCC_PORT_C].enable = RCC_AHBENR_GPIOCEN;
#else
	(*portHandlesStatic)[RCC_PORT_C].exists = false;
#endif

#ifdef RCC_AHBENR_GPIODEN
	(*portHandlesStatic)[RCC_PORT_D].exists = true;
	(*portHandlesStatic)[RCC_PORT_D].enable = RCC_AHBENR_GPIODEN;
#else
	(*portHandlesStatic)[RCC_PORT_D].exists = false;
#endif

#ifdef RCC_AHBENR_GPIOEEN
	(*portHandlesStatic)[RCC_PORT_E].exists = true;
	(*portHandlesStatic)[RCC_PORT_E].enable = RCC_AHBENR_GPIOEEN;
#else
	(*portHandlesStatic)[RCC_PORT_E].exists = false;
#endif

#ifdef RCC_AHBENR_GPIOFEN
	(*portHandlesStatic)[RCC_PORT_F].exists = true;
	(*portHandlesStatic)[RCC_PORT_F].enable = RCC_AHBENR_GPIOFEN;
#else
	(*portHandlesStatic)[RCC_PORT_F].exists = false;
#endif
	
	return portHandlesStatic;
}

static std::vector<RccPortHandle>* portHandlesStatic = portHandles();


// --- PERIPHERAL HANDLES ---
std::vector<RccPeripheralHandle>* peripheralHandles() {
	RccPeripheralHandle handle;
	static std::vector<RccPeripheralHandle>* peripheralHandlesStatic = new std::vector<RccPeripheralHandle>(37, handle);
	
	// AHB
	
#ifdef RCC_AHBENR_TSCEN
	(*peripheralHandlesStatic)[RCC_TSC].exists = true;
	(*peripheralHandlesStatic)[RCC_TSC].enr = &(RCC->AHBENR);
	(*peripheralHandlesStatic)[RCC_TSC].enable = RCC_AHBENR_TSCEN;
#else
	(*peripheralHandlesStatic)[RCC_TSC].exists = false;
#endif

#ifdef RCC_AHBENR_CRCEN
	(*peripheralHandlesStatic)[RCC_CRC].exists = true;
	(*peripheralHandlesStatic)[RCC_CRC].enr = &(RCC->AHBENR);
	(*peripheralHandlesStatic)[RCC_CRC].enable = RCC_AHBENR_CRCEN;
#else
	(*peripheralHandlesStatic)[RCC_CRC].exists = false;
#endif

#ifdef RCC_AHBENR_FLITFEN
	(*peripheralHandlesStatic)[RCC_FLITF].exists = true;
	(*peripheralHandlesStatic)[RCC_FLITF].enr = &(RCC->AHBENR);
	(*peripheralHandlesStatic)[RCC_FLITF].enable = RCC_AHBENR_FLITFEN;
#else
	(*peripheralHandlesStatic)[RCC_FLITF].exists = false;
#endif

#ifdef RCC_AHBENR_SRAMEN
	(*peripheralHandlesStatic)[RCC_SRAM].exists = true;
	(*peripheralHandlesStatic)[RCC_SRAM].enr = &(RCC->AHBENR);
	(*peripheralHandlesStatic)[RCC_SRAM].enable = RCC_AHBENR_SRAMEN;
#else
	(*peripheralHandlesStatic)[RCC_SRAM].exists = false;
#endif

#ifdef RCC_AHBENR_DMA2EN
	(*peripheralHandlesStatic)[RCC_DMA2].exists = true;
	(*peripheralHandlesStatic)[RCC_DMA2].enr = &(RCC->AHBENR);
	(*peripheralHandlesStatic)[RCC_DMA2].enable = RCC_AHBENR_DMA2EN;
#else
	(*peripheralHandlesStatic)[RCC_DMA2].exists = false;
#endif

#ifdef RCC_AHBENR_DMAEN
	(*peripheralHandlesStatic)[RCC_DMA].exists = true;
	(*peripheralHandlesStatic)[RCC_DMA].enr = &(RCC->AHBENR);
	(*peripheralHandlesStatic)[RCC_DMA].enable = RCC_AHBENR_DMAEN;
#else
	(*peripheralHandlesStatic)[RCC_DMA].exists = false;
#endif
	
	// APB2

#ifdef RCC_APB2ENR_SYSCFGCOMPEN
	(*peripheralHandlesStatic)[RCC_SYSCFGCOMP].exists = true;
	(*peripheralHandlesStatic)[RCC_SYSCFGCOMP].enr = &(RCC->APB2ENR);
	(*peripheralHandlesStatic)[RCC_SYSCFGCOMP].enable = RCC_APB2ENR_SYSCFGCOMPEN;
#else
	(*peripheralHandlesStatic)[RCC_SYSCFGCOMP].exists = false;
#endif

#ifdef RCC_APB2ENR_USART6EN
	(*peripheralHandlesStatic)[RCC_USART6].exists = true;
	(*peripheralHandlesStatic)[RCC_USART6].enr = &(RCC->APB2ENR);
	(*peripheralHandlesStatic)[RCC_USART6].enable = RCC_APB2ENR_USART6EN;
#else
	(*peripheralHandlesStatic)[RCC_USART6].exists = false;
#endif

#ifdef RCC_APB2ENR_USART7EN
	(*peripheralHandlesStatic)[RCC_USART7].exists = true;
	(*peripheralHandlesStatic)[RCC_USART7].enr = &(RCC->APB2ENR);
	(*peripheralHandlesStatic)[RCC_USART7].enable = RCC_APB2ENR_USART7EN;
#else
	(*peripheralHandlesStatic)[RCC_USART7].exists = false;
#endif

#ifdef RCC_APB2ENR_USART8EN
	(*peripheralHandlesStatic)[RCC_USART8].exists = true;
	(*peripheralHandlesStatic)[RCC_USART8].enr = &(RCC->APB2ENR);
	(*peripheralHandlesStatic)[RCC_USART8].enable = RCC_APB2ENR_USART8EN;
#else
	(*peripheralHandlesStatic)[RCC_USART8].exists = false;
#endif

#ifdef RCC_APB2ENR_ADCEN
	(*peripheralHandlesStatic)[RCC_ADC].exists = true;
	(*peripheralHandlesStatic)[RCC_ADC].enr = &(RCC->APB2ENR);
	(*peripheralHandlesStatic)[RCC_ADC].enable = RCC_APB2ENR_ADCEN;
#else
	(*peripheralHandlesStatic)[RCC_ADC].exists = false;
#endif

#ifdef RCC_APB2ENR_TIM1EN
	(*peripheralHandlesStatic)[RCC_TIM1].exists = true;
	(*peripheralHandlesStatic)[RCC_TIM1].enr = &(RCC->APB2ENR);
	(*peripheralHandlesStatic)[RCC_TIM1].enable = RCC_APB2ENR_TIM1EN;
#else
	(*peripheralHandlesStatic)[RCC_TIM1].exists = false;
#endif

#ifdef RCC_APB2ENR_SPI1EN
	(*peripheralHandlesStatic)[RCC_SPI1].exists = true;
	(*peripheralHandlesStatic)[RCC_SPI1].enr = &(RCC->APB2ENR);
	(*peripheralHandlesStatic)[RCC_SPI1].enable = RCC_APB2ENR_SPI1EN;
#else
	(*peripheralHandlesStatic)[RCC_SPI1].exists = false;
#endif

#ifdef RCC_APB2ENR_USART1EN
	(*peripheralHandlesStatic)[RCC_USART1].exists = true;
	(*peripheralHandlesStatic)[RCC_USART1].enr = &(RCC->APB2ENR);
	(*peripheralHandlesStatic)[RCC_USART1].enable = RCC_APB2ENR_USART1EN;
#else
	(*peripheralHandlesStatic)[RCC_USART1].exists = false;
#endif

#ifdef RCC_APB2ENR_TIM15EN
	(*peripheralHandlesStatic)[RCC_TIM15].exists = true;
	(*peripheralHandlesStatic)[RCC_TIM15].enr = &(RCC->APB2ENR);
	(*peripheralHandlesStatic)[RCC_TIM15].enable = RCC_APB2ENR_TIM15EN;
#else
	(*peripheralHandlesStatic)[RCC_TIM15].exists = false;
#endif

#ifdef RCC_APB2ENR_TIM16EN
	(*peripheralHandlesStatic)[RCC_TIM16].exists = true;
	(*peripheralHandlesStatic)[RCC_TIM16].enr = &(RCC->APB2ENR);
	(*peripheralHandlesStatic)[RCC_TIM16].enable = RCC_APB2ENR_TIM16EN;
#else
	(*peripheralHandlesStatic)[RCC_TIM16].exists = false;
#endif

#ifdef RCC_APB2ENR_TIM17EN
	(*peripheralHandlesStatic)[RCC_TIM17].exists = true;
	(*peripheralHandlesStatic)[RCC_TIM17].enr = &(RCC->APB2ENR);
	(*peripheralHandlesStatic)[RCC_TIM17].enable = RCC_APB2ENR_SYSCFGCOMPEN;
#else
	(*peripheralHandlesStatic)[RCC_TIM17].exists = false;
#endif

#ifdef RCC_APB2ENR_DBGMCUEN
	(*peripheralHandlesStatic)[RCC_DBGMCU].exists = true;
	(*peripheralHandlesStatic)[RCC_DBGMCU].enr = &(RCC->APB2ENR);
	(*peripheralHandlesStatic)[RCC_DBGMCU].enable = RCC_APB2ENR_DBGMCUEN;
#else
	(*peripheralHandlesStatic)[RCC_DBGMCU].exists = false;
#endif
	
	// APB1

#ifdef RCC_APB1ENR_TIM2EN
	(*peripheralHandlesStatic)[RCC_TIM2].exists = true;
	(*peripheralHandlesStatic)[RCC_TIM2].enr = &(RCC->APB1ENR);
	(*peripheralHandlesStatic)[RCC_TIM2].enable = RCC_APB1ENR_TIM2EN;
#else
	(*peripheralHandlesStatic)[RCC_TIM2].exists = false;
#endif

#ifdef RCC_APB1ENR_TIM3EN
	(*peripheralHandlesStatic)[RCC_TIM3].exists = true;
	(*peripheralHandlesStatic)[RCC_TIM3].enr = &(RCC->APB1ENR);
	(*peripheralHandlesStatic)[RCC_TIM3].enable = RCC_APB1ENR_TIM3EN;
#else
	(*peripheralHandlesStatic)[RCC_TIM3].exists = false;
#endif

#ifdef RCC_APB1ENR_TIM6EN
	(*peripheralHandlesStatic)[RCC_TIM6].exists = true;
	(*peripheralHandlesStatic)[RCC_TIM6].enr = &(RCC->APB1ENR);
	(*peripheralHandlesStatic)[RCC_TIM6].enable = RCC_APB1ENR_TIM6EN;
#else
	(*peripheralHandlesStatic)[RCC_TIM6].exists = false;
#endif

#ifdef RCC_APB1ENR_TIM7EN
	(*peripheralHandlesStatic)[RCC_TIM7].exists = true;
	(*peripheralHandlesStatic)[RCC_TIM7].enr = &(RCC->APB1ENR);
	(*peripheralHandlesStatic)[RCC_TIM7].enable = RCC_APB1ENR_TIM7EN;
#else
	(*peripheralHandlesStatic)[RCC_TIM7].exists = false;
#endif

#ifdef RCC_APB1ENR_TIM14EN
	(*peripheralHandlesStatic)[RCC_TIM14].exists = true;
	(*peripheralHandlesStatic)[RCC_TIM14].enr = &(RCC->APB1ENR);
	(*peripheralHandlesStatic)[RCC_TIM14].enable = RCC_APB1ENR_TIM14EN;
#else
	(*peripheralHandlesStatic)[RCC_TIM14].exists = false;
#endif

#ifdef RCC_APB1ENR_WWDGEN
	(*peripheralHandlesStatic)[RCC_WWDG].exists = true;
	(*peripheralHandlesStatic)[RCC_WWDG].enr = &(RCC->APB1ENR);
	(*peripheralHandlesStatic)[RCC_WWDG].enable = RCC_APB1ENR_WWDGEN;
#else
	(*peripheralHandlesStatic)[RCC_WWDG].exists = false;
#endif

#ifdef RCC_APB1ENR_SPI2EN
	(*peripheralHandlesStatic)[RCC_SPI2].exists = true;
	(*peripheralHandlesStatic)[RCC_SPI2].enr = &(RCC->APB1ENR);
	(*peripheralHandlesStatic)[RCC_SPI2].enable = RCC_APB1ENR_SPI2EN;
#else
	(*peripheralHandlesStatic)[RCC_SPI2].exists = false;
#endif

#ifdef RCC_APB1ENR_USART2EN
	(*peripheralHandlesStatic)[RCC_USART2].exists = true;
	(*peripheralHandlesStatic)[RCC_USART2].enr = &(RCC->APB1ENR);
	(*peripheralHandlesStatic)[RCC_USART2].enable = RCC_APB1ENR_USART2EN;
#else
	(*peripheralHandlesStatic)[RCC_USART2].exists = false;
#endif

#ifdef RCC_APB1ENR_USART3EN
	(*peripheralHandlesStatic)[RCC_USART3].exists = true;
	(*peripheralHandlesStatic)[RCC_USART3].enr = &(RCC->APB1ENR);
	(*peripheralHandlesStatic)[RCC_USART3].enable = RCC_APB1ENR_USART3EN;
#else
	(*peripheralHandlesStatic)[RCC_USART3].exists = false;
#endif

#ifdef RCC_APB1ENR_USART4EN
	(*peripheralHandlesStatic)[RCC_USART4].exists = true;
	(*peripheralHandlesStatic)[RCC_USART4].enr = &(RCC->APB1ENR);
	(*peripheralHandlesStatic)[RCC_USART4].enable = RCC_APB1ENR_USART4EN;
#else
	(*peripheralHandlesStatic)[RCC_USART4].exists = false;
#endif

#ifdef RCC_APB1ENR_USART5EN
	(*peripheralHandlesStatic)[RCC_USART5].exists = true;
	(*peripheralHandlesStatic)[RCC_USART5].enr = &(RCC->APB1ENR);
	(*peripheralHandlesStatic)[RCC_USART5].enable = RCC_APB1ENR_USART5EN;
#else
	(*peripheralHandlesStatic)[RCC_USART5].exists = false;
#endif

#ifdef RCC_APB1ENR_I2C1EN
	(*peripheralHandlesStatic)[RCC_I2C1].exists = true;
	(*peripheralHandlesStatic)[RCC_I2C1].enr = &(RCC->APB1ENR);
	(*peripheralHandlesStatic)[RCC_I2C1].enable = RCC_APB1ENR_I2C1EN;
#else
	(*peripheralHandlesStatic)[RCC_I2C1].exists = false;
#endif

#ifdef RCC_APB1ENR_I2C2EN
	(*peripheralHandlesStatic)[RCC_I2C2].exists = true;
	(*peripheralHandlesStatic)[RCC_I2C2].enr = &(RCC->APB1ENR);
	(*peripheralHandlesStatic)[RCC_I2C2].enable = RCC_APB1ENR_I2C2EN;
#else
	(*peripheralHandlesStatic)[RCC_I2C2].exists = false;
#endif

#ifdef RCC_APB1ENR_USBEN
	(*peripheralHandlesStatic)[RCC_USB].exists = true;
	(*peripheralHandlesStatic)[RCC_USB].enr = &(RCC->APB1ENR);
	(*peripheralHandlesStatic)[RCC_USB].enable = RCC_APB1ENR_USBEN;
#else
	(*peripheralHandlesStatic)[RCC_USB].exists = false;
#endif

#ifdef RCC_APB1ENR_CANEN
	(*peripheralHandlesStatic)[RCC_CAN].exists = true;
	(*peripheralHandlesStatic)[RCC_CAN].enr = &(RCC->APB1ENR);
	(*peripheralHandlesStatic)[RCC_CAN].enable = RCC_APB1ENR_CANEN;
#else
	(*peripheralHandlesStatic)[RCC_CAN].exists = false;
#endif

#ifdef RCC_APB1ENR_CRSEN
	(*peripheralHandlesStatic)[RCC_CRS].exists = true;
	(*peripheralHandlesStatic)[RCC_CRS].enr = &(RCC->APB1ENR);
	(*peripheralHandlesStatic)[RCC_CRS].enable = RCC_APB1ENR_CRSEN;
#else
	(*peripheralHandlesStatic)[RCC_CRS].exists = false;
#endif

#ifdef RCC_APB1ENR_PWREN
	(*peripheralHandlesStatic)[RCC_PWR].exists = true;
	(*peripheralHandlesStatic)[RCC_PWR].enr = &(RCC->APB1ENR);
	(*peripheralHandlesStatic)[RCC_PWR].enable = RCC_APB1ENR_PWREN;
#else
	(*peripheralHandlesStatic)[RCC_PWR].exists = false;
#endif

#ifdef RCC_APB1ENR_DACEN
	(*peripheralHandlesStatic)[RCC_DAC].exists = true;
	(*peripheralHandlesStatic)[RCC_DAC].enr = &(RCC->APB1ENR);
	(*peripheralHandlesStatic)[RCC_DAC].enable = RCC_APB1ENR_DACEN;
#else
	(*peripheralHandlesStatic)[RCC_DAC].exists = false;
#endif

#ifdef RCC_APB1ENR_CECEN
	(*peripheralHandlesStatic)[RCC_CEC].exists = true;
	(*peripheralHandlesStatic)[RCC_CEC].enr = &(RCC->APB1ENR);
	(*peripheralHandlesStatic)[RCC_CEC].enable = RCC_APB1ENR_CECEN;
#else
	(*peripheralHandlesStatic)[RCC_CEC].exists = false;
#endif
	
	return peripheralHandlesStatic;
}

static std::vector<RccPeripheralHandle>* perHandlesStatic = peripheralHandles();


// Public methods:

// --- ENABLE ---
// Enable the target peripheral. 
// Returns true if the peripheral was successfully turned on, or if the peripheral was already on.
// Returns false if the peripheral could not be turned on. 
bool Rcc::enable(RccPeripheral peripheral) {
	//static std::vector<RccPeripheralHandle> &perHandlesStatic = Rcc::peripheralHandles();
	uint8_t perNum = (uint8_t) peripheral;
	RccPeripheralHandle &ph = (*perHandlesStatic)[perNum];
	
	if (ph.exists == false) {
		// TODO: set reason.
		return false;
	}
	
	// Check the current peripheral status.
	if (ph.count > 0) {
		if (ph.count >= handle_max) {
			// Reached maximum handles. Return false to prevent counter overflow.
			// TODO: set reason.
			return false;
		}
		
		// Increase handler count by one.
		ph.count++;
	}
	else {
		// Activate the peripheral.
		ph.count = 1;
		*(ph.enr) |= (1 << ph.enable);
	}
	
	return true;
}


// --- DISABLE ---
// Disable the target peripheral.
// Returns true if the disable request was received but not processed due to outstanding handles, or
// if the peripheral was successfully disabled.
// Returns false if the request was rejected or disabling the peripheral failed.
bool Rcc::disable(RccPeripheral peripheral) {
	//static std::vector<RccPeripheralHandle> &perHandlesStatic = Rcc::peripheralHandles();
	uint8_t perNum = (uint8_t) peripheral;
	RccPeripheralHandle &ph = (*perHandlesStatic)[perNum];
	
	if (ph.exists == false) {
		// TODO: set reason.
		return false;
	}
	
	if (ph.count > 1) {
		// Decrease handler count by one.
		ph.count--;
	}
	else {
		// Deactivate the peripheral.
		ph.count = 0;
		*(ph.enr) &= ~(1 << ph.enable);
	}
	
	return true;
}


// --- ENABLE PORT ---
// Returns true if the port was already enabled, or was successfully enabled.
// Returns false if the port could not be enabled.
bool Rcc::enablePort(RccPort port) {
	//static std::vector<RccPortHandle> &portHandlesStatic = Rcc::portHandles();
	uint8_t portNum = (uint8_t) port;
	RccPortHandle &ph = (*portHandlesStatic)[portNum];
	
	if (ph.exists == false) {
		// TODO: set reason.
		return false; 
	}
	
	// Check the current port status.
	if (ph.count > 0) {
		if (ph.count >= handle_max) {
			// Reached maximum handles. Return false to prevent counter overflow.
			// TODO: set reason.
			return false;
		}
		
		// Increase handler count by one.
		ph.count++;
	}
	else {
		// Activate the port.
		ph.count = 1;
		RCC->AHBENR |= (1 << ph.enable);
	}
	
	return true;
}


// --- DISABLE PORT ---
// Returns true if the port is already disabled, if the request was accepted, or the port disabled.
// Returns false if the requested was rejected, or the port could not be disabled.
bool Rcc::disablePort(RccPort port) {
	//static std::vector<RccPortHandle> &portHandlesStatic = Rcc::portHandles();
	uint8_t portNum = (uint8_t) port;
	RccPortHandle &ph = (*portHandlesStatic)[portNum];
	
	if (ph.exists == false) {
		// TODO: set reason.
		return false; 
	}
	
	// Check the current port status.
	if (ph.count > 1) {
		// Decrease handler count by one.
		ph.count--;
	}
	else {
		// Deactivate the port.
		ph.count = 0;
		RCC->AHBENR &= ~(1 << ph.enable);
	}
	
	return true;
}