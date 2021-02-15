#include <stdio.h>  
#include <stdint.h>  
#define DELTA 0x9e3779b9  
#define MX (((z>>5^y<<2) + (y>>3^z<<4)) ^ ((sum^y) + (key[(p&3)^e] ^ z)))  

void btea(uint32_t *v, int n, uint32_t const key[4])
{
	uint32_t y, z, sum;
	unsigned p, rounds, e;
	if (n > 1)            /* Coding Part */
	{
		rounds = 6 + 52 / n;
		sum = 0;
		z = v[n - 1];
		do
		{
			sum += DELTA;
			e = (sum >> 2) & 3;
			for (p = 0; p<n - 1; p++)
			{
				y = v[p + 1];
				z = v[p] += MX;
			}
			y = v[0];
			z = v[n - 1] += MX;
		} while (--rounds);
	}
	else if (n < -1)      /* Decoding Part */
	{
		n = -n;
		rounds = 6 + 52 / n;
		sum = rounds*DELTA;
		y = v[0];
		do
		{
			e = (sum >> 2) & 3;
			for (p = n - 1; p>0; p--)
			{
				z = v[p - 1];
				y = v[p] -= MX;
			}
			z = v[n - 1];
			y = v[0] -= MX;
			sum -= DELTA;
		} while (--rounds);
	}
}


int main()
{
	//03e0164dd30553aa
	       // uint32_t a[2] = { (unsigned int)0xd2cfdad7, 0x9ac8d5d4 };
           uint32_t w[35]={(unsigned int)0xE74EB323, (unsigned int)0xB7A72836,(unsigned int) 0x59CA6FE2, (unsigned int)0x967CC5C1,(unsigned int) 0xE7802674,(unsigned int) 0x3D2D54E6, (unsigned int)0x8A9D0356, (unsigned int)0x99DCC39C,(unsigned int) 0x7026D8ED, (unsigned int)0x6A33FDAD, (unsigned int)0xF496550A, (unsigned int)0x5C9C6F9E, (unsigned int)0x1BE5D04C, (unsigned int)0x6723AE17, (unsigned int)0x5270A5C2, (unsigned int)0xAC42130A,(unsigned int) 0x84BE67B2, (unsigned int)0x705CC779, (unsigned int)0x5C513D98,(unsigned int) 0xFB36DA2D, (unsigned int)0x22179645,(unsigned int) 0x5CE3529D, (unsigned int)0xD189E1FB, (unsigned int)0xE85BD489, (unsigned int)0x73C8D11F, (unsigned int)0x54B5C196, (unsigned int)0xB67CB490, (unsigned int)0x2117E4CA, (unsigned int)0x9DE3F994, (unsigned int)0x2F5AA1AA, (unsigned int)0xA7E801FD, (unsigned int)0xC30D6EAB, (unsigned int)0x1BADDC9C,(unsigned int) 0x3453B04A, (unsigned int)0x00A406F9};

	//uint32_t v[6] = { (unsigned int)0x40cea5bc, (unsigned int)0xe7b2b2f4,(unsigned int)0x129d12a9,(unsigned int)0x5bc810ae,(unsigned int)0x1d06d73d,(unsigned int)0xdcf870dc };
			uint32_t const k[4] = { (unsigned int)0x1, (unsigned int)0x2, (unsigned int)0x3, (unsigned int)0x4 };
			int n = 6; //n的绝对值表示v的长度，取正表示加密，取负表示解密  
			// v为要加密的数据是两个32位无符号整数  
			// k为加密解密密钥，为4个32位无符号整数，即密钥长度为128位  
			//printf("加密前原始数据：%x %x\n", v[0], v[1]);
			btea(w, -n, k);
			printf("加密后的数据：%x %x %x %x %x\n", w[0], w[1],w[2],w[3],w[4],w[5]);
			//btea(v, -n, k);
			//printf("解密后的数据：%x %x\n", v[0], v[1]);
			
			
	
}