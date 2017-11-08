/*
 *                                   1byt3
 *
 *                              License Notice
 *
 * 1byt3 provides a commercial license agreement for this software. This
 * commercial license can be used for development of proprietary/commercial
 * software. Under this commercial license you do not need to comply with the
 * terms of the GNU Affero General Public License, either version 3 of the
 * License, or (at your option) any later version.
 *
 * If you don't receive a commercial license from us (1byt3), you MUST assume
 * that this software is distributed under the GNU Affero General Public
 * License, either version 3 of the License, or (at your option) any later
 * version.
 *
 * Contact us for additional information: customers at 1byt3.com
 *
 *                          End of License Notice
 */

/*
 * MQTT 5 Low Level Packet Library
 *
 * Copyright (C) 2017 1byt3, customers at 1byt3.com
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Affero General Public License as
 * published by the Free Software Foundation, either version 3 of the
 * License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU Affero General Public License for more details.
 *
 * You should have received a copy of the GNU Affero General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include "PktSubscribe.hpp"
#include "test_Common.hpp"

int test(void)
{
	const char *msg = "Hello, World!";
	m5::PktSubscribe *subs;
	m5::AppBuf buf(256);

	subs = new m5::PktSubscribe();
	subs->append(msg, 0x01);
	subs->append(msg, 0x02);
	subs->append(msg, 0x03);
	subs->packetId(0xABCD);
	subs->writeTo(buf);

	std::cout << "Subscribe\n";
	m5::printArray(buf.data(), buf.length());

	delete subs;

	return 0;
}


int main(void)
{
	int rc;

	rc = test();
	test_rc(rc, "PktSubscribe");

	return 0;
}

