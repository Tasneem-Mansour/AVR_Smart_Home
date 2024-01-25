/*
 * TWI_config.h
 *
 *  Created on: Jan 1, 2024
 *      Author: Tasneem
 */

#ifndef TWI_CONFIG_H_
#define TWI_CONFIG_H_

#define MASTER_ADDRESS		50
#define SLAVE_ADDRESS		20


/*********TWSR BITS*********/
#define TWSR_TWPS0			0
#define TWSR_TWPS1			1

/*********TWCR BITS*********/
#define TWCR_TWINT			7
#define TWCR_TWEA			6
#define TWCR_TWSTA			5
#define TWCR_TWSTO			4
#define TWCR_TWEN			2

/*********TWDR BITS*********/
#define TWDR_TWD0			0


#endif /* TWI_CONFIG_H_ */
