/********************************************
**
**	nwa �ե��`�ޥåȤˤĤ���
**
**		ȫ��Ȥ��Ƥ����¤Θ����֤�
**		NWA Header
**		data offset index
**		data block<0>
**		data block<1>
**		...
**		data block<N>
**
**	NWA Header: �ե��������^���� 44 bytes
**		magic number �ʤɤϤʤ��Τ�nwa �ե����뤫��
**		�ǩ`���������Ԥ����жϤ����Ҫ������
**		�ǩ`����ȫ�� little endian �ǡ�
**		short(signed 2byte)�ޤ��� int(signed 4byte) �Ǥ��롣
**
**		+00 short   channel ��(1/2)
**		+02 short   sample һ�Ĥ������ bit ��(16)
**		+04 int     �ܲ���(һ�뤢����Υǩ`����)
**		+08 int     �R�s��٥룺-1~5.2����С�Υǩ`����0�����Ώ�Ԫ��(-1�ϟo�R�sraw�ǩ`���Ȥߤʤ����)
**		+12 int     ?
**		+16 int     �֥�å���
**		+20 int     չ�_��Υǩ`���δ󤭤�(�Х��ȅgλ)
**		+24 int     �R�s�r�Υǩ`���δ󤭤�(nwa �ե�����δ󤭤����Х��ȅgλ)
**		+28 int     ����ץ�����չ�_��Υǩ`����(16bit data�ʤ� short �gλ==����ץ�gλ�Υǩ`���δ󤭤�)
**		+32 int     �ǩ`�����֥�å���չ�_�����r�Υ���ץ�gλ�Υǩ`����
**		+36 int     ��K�֥�å���չ�_�����r�Υ���ץ�gλ�Υǩ`����
**		+40 int     ?
**
**	data offset index
**		ȫ�֥�å��� x 4 byte �Υǩ`��
**		���줾�� int �Υǩ`����ȫ�֥�å����A���Ƥ���
**
**		�ǩ`���֥�å������^��ָ���ե��������^�����λ��(���ե��å�)
**		����{����Ƥ���
**
**	data block
**		�L���Ͽɉ䡣չ�_���뤳�Ȥ�һ���δ󤭤����ĥǩ`����չ�_����롣
**		�ǩ`����DPCM��ʽ��Ԫ PCM �ǩ`���� a,b,c �ʤ�� (a),b-a, c-b ��
**		���ä���֥ǩ`����������3-5bit,ָ��3bit����ʽ�Ǳ��椵��Ƥ��롣
**		�Y���Ĥˡ�16bit �Υǩ`�����य�Έ��� 6-8bit �Ǹ�{����롣
**		�����Υӥå����ψR�s��٥�0��5bit���R�s��٥�2��3bit�Ȥʤ롣
**		���¡��R�s��٥�2�Έ��ϤˤĤ���Ԓ���M��롣
**		��Υ��Έ��ϣ�
**			+00 short  �֥�å��ڤ�����Υǩ`��
**			+02- bit stream
**		���ƥ쥪�Έ��ϣ�
**			+00 short  ��(?)�����ͥ������Υǩ`��
**			+02 short  ��(?)�����ͥ������Υǩ`��
**			+04- bit stream
**
**		��֥ǩ`���ξ��Ȥ��ߤ��ʤ��ΤǸ��֥�å������^��
**		���_�ʥǩ`���ˤ���a�������(��)
**
**	bit stream
**		little endian
**		+0 - +2 : ָ��
**		+3 - +5 : ����
**		����ʽ�������� a,b,c �Ȥ���8bit�ǩ`��������С�
**		a&0x07 : �ǩ`������ָ��
**		(a>>3)&0x07 : �ǩ`�����΁���(signed ;
**		((b<<2)|(a>>6))&0x07 : �ǩ`������ָ��
**		(b>>1)&0x07 : �ǩ`�����΁���
**		�Ȥʤ롣
**		��������ָ���΂��ˤ�ꁢ����bit�����仯���뤳�Ȥ����롣
**		ָ�� = 1 - 6 �Έ��ϣ�
**			a=ָ����b=������p=ǰ�Υǩ`���Ȥ��ơ���ؤΥǩ`��d ��
**			b��2bitĿ�����äƤ�����ϣ�
**				d = p - (b&3)<<(4+a)
**			���äƤʤ����ϣ�
**				d = p + (b&3)<<(4+a)
**		ָ�� = 0 �Έ��ϣ������ϴ��ڤ��ʤ�(�ǩ`����3bit�Ȥʤ�)
**			d = p
**			���Ǵ����ե��`���������ե����� (complevel == 5) �Ǥϥ���󥰥��R�s�ä�ʹ���Ƥ��롣
**		ָ�� = 7
**			�Τ� bit �����äƤ�����ϣ�
**				d = 0 (�F��δʹ��)
**				(�ǩ`����4bit�Ȥʤ�)
**			�Τ� bit �����äƤʤ����ϣ�
**				complevel = 0,1,2:
**				   ���� b = 6bit
**				   b �� 5bit Ŀ�����äƤ�����ϣ�
**					d = p - (b&0x1f)<<(4+7)
**				   ���äƤʤ����ϣ�
**					d = p + (b&0x1f)<<(4+7)
**				   (�ǩ`����10bit�Ȥʤ�)
**				complevel = 3,4,5:
**				   ���� b = 8bit
**				   b �� 7bit Ŀ�����äƤ�����ϣ�
**					d = p - (b&0x7f)<<9
**				   ���äƤʤ����ϣ�
**					d = p + (b&0x1f)<<9
**				   (�ǩ`����10bit�Ȥʤ�)
**
**		�R�s��٥뤬���ʤ���ϡ����Ȥ��ЈR�s��٥�==0��
**			ָ��==1~6��d������λbit�����äƤ������
**				d = p - (b&0x0f)<<(2+a)
**			ָ��==7��d������λbit�����äƤ������
**				d = p - (b&0x7f)<<(2+7)
**				(b : 8bit�ʤΤǥǩ`����12bit�Ȥʤ�)
**		�Τ褦�ˡ����Ȥ������仯����褦�ˤʤäƤ��롣
**
**	�إå��i���z�ߤˤĤ��Ƥ�NWAData::ReadHeader()����
**	bit stream ����Υǩ`��չ�_�ˤĤ��Ƥ� NWADecode()����
**************************************************************
*/


#include "my.h"
#include<string.h>
#include "endian.hpp"
#include "StreamWriter.h"



inline int getbits(const char*& data, int& shift, int bits) {
	if (shift > 8) { data++; shift -= 8; }
	int ret = read_little_endian_short(data) >> shift;
	shift += bits;
	return ret & ((1 << bits) - 1); /* mask */
}

/* ָ�����줿��ʽ�Υإå���Ĥ��� */
const char* make_wavheader(int size, int channels, int bps, int freq) {
	static char wavheader[0x2c] = {
		'R', 'I', 'F', 'F',
		0, 0, 0, 0, /* +0x04: riff size*/
		'W', 'A', 'V', 'E',
		'f', 'm', 't', ' ',
		16, 0, 0, 0, /* +0x10 : fmt size=0x10 */
		1, 0,    /* +0x14 : tag : pcm = 1 */
		2, 0,    /* +0x16 : channels */
		0, 0, 0, 0, /* +0x18 : samples per second */
		0, 0, 0, 0, /* +0x1c : average bytes per second */
		0, 0,     /* +0x20 : block alignment */
		0, 0,     /* +0x22 : bits per sample */
		'd', 'a', 't', 'a',
		0, 0, 0, 0 };/* +0x28 : data size */
	write_little_endian_int(wavheader + 0x04, size + 0x24);
	write_little_endian_int(wavheader + 0x28, size);
	write_little_endian_short(wavheader + 0x16, channels);
	write_little_endian_short(wavheader + 0x22, bps);
	write_little_endian_int(wavheader + 0x18, freq);
	int byps = (bps + 7) >> 3;
	write_little_endian_int(wavheader + 0x1c, freq*byps*channels);
	write_little_endian_short(wavheader + 0x20, byps*channels);
	return wavheader;
}

/* NWA �� bitstreamչ�_�˱�Ҫ�Ȥʤ���� */
class NWAInfo {
	int channels;
	int bps;
	int complevel;
	bool use_runlength;
public:
	NWAInfo(int c, int b, int cl, bool rl) {
		channels = c;
		bps = b;
		complevel = cl;
		use_runlength = rl;
	}
	int Channels(void) const{ return channels; }
	int Bps(void) const { return bps; }
	int CompLevel(void) const { return complevel; }
	int UseRunLength(void) const { return use_runlength; }
};

template<class NWAI> void NWADecode(const NWAI& info, const char* data, char* outdata, int datasize, int outdatasize) {
	int d[2];
	int i;
	int shift = 0;
	const char* dataend = data + datasize;
	/* ����Υǩ`�����i���z�� */
	if (info.Bps() == 8) { d[0] = *data++; datasize--; }
	else /* info.Bps() == 16 */ { d[0] = read_little_endian_short(data); data += 2; datasize -= 2; }
	if (info.Channels() == 2) {
		if (info.Bps() == 8) { d[1] = *data++; datasize--; }
		else /* info.Bps() == 16 */ { d[1] = read_little_endian_short(data); data += 2; datasize -= 2; }
	}
	int dsize = outdatasize / (info.Bps() / 8);
	int flip_flag = 0; /* stereo �� */
	int runlength = 0;
	for (i = 0; i < dsize; i++) {
		if (data >= dataend) break;
		if (runlength == 0) { // ���ԩ`��`���ФǤʤ��ʤ�ǩ`���i���z��
			int type = getbits(data, shift, 3);
			/* type �ˤ���᪣�0, 1-6, 7 */
			if (type == 7) {
				/* 7 : �󤭤ʲ�� */
				/* RunLength() �Є��r��CompLevel==5, �����ե�����) �Ǥϟo�� */
				if (getbits(data, shift, 1) == 1) {
					d[flip_flag] = 0; /* δʹ�� */
				}
				else {
					int BITS, SHIFT;
					if (info.CompLevel() >= 3) {
						BITS = 8;
						SHIFT = 9;
					}
					else {
						BITS = 8 - info.CompLevel();
						SHIFT = 2 + 7 + info.CompLevel();
					}
					const int MASK1 = (1 << (BITS - 1));
					const int MASK2 = (1 << (BITS - 1)) - 1;
					int b = getbits(data, shift, BITS);
					if (b&MASK1)
						d[flip_flag] -= (b&MASK2) << SHIFT;
					else
						d[flip_flag] += (b&MASK2) << SHIFT;
				}
			}
			else if (type != 0) {
				/* 1-6 : ͨ���β�� */
				int BITS, SHIFT;
				if (info.CompLevel() >= 3) {
					BITS = info.CompLevel() + 3;
					SHIFT = 1 + type;
				}
				else {
					BITS = 5 - info.CompLevel();
					SHIFT = 2 + type + info.CompLevel();
				}
				const int MASK1 = (1 << (BITS - 1));
				const int MASK2 = (1 << (BITS - 1)) - 1;
				int b = getbits(data, shift, BITS);
				if (b&MASK1)
					d[flip_flag] -= (b&MASK2) << SHIFT;
				else
					d[flip_flag] += (b&MASK2) << SHIFT;
			}
			else { /* type == 0 */
				/* ����󥰥��R�s�ʤ��Έ��ϤϤʤˤ⤷�ʤ� */
				if (info.UseRunLength() == true) {
					/* ����󥰥��R�s����Έ��� */
					runlength = getbits(data, shift, 1);
					if (runlength == 1) {
						runlength = getbits(data, shift, 2);
						if (runlength == 3) {
							runlength = getbits(data, shift, 8);
						}
					}
				}
			}
		}
		else {
			runlength--;
		}
		if (info.Bps() == 8) {
			*outdata++ = d[flip_flag];
		}
		else {
			write_little_endian_short(outdata, d[flip_flag]);
			outdata += 2;
		}
		if (info.Channels() == 2) flip_flag ^= 1; /* channel �Ф��椨 */
	}
	return;
};

class NWAData {
public:
	int channels;
	int bps; /* bits per sample */
	int freq; /* samples per second */
private:
	int complevel; /* compression level */
	int use_runlength; /* run length encoding */
public:
	int blocks; /* block count */
	int datasize; /* all data size */
private:
	int compdatasize; /* compressed data size */
	int samplecount; /* all samples */
	int blocksize; /* samples per block */
	int restsize; /* samples of the last block */
	int dummy2; /* ? : 0x89 */
	int curblock;
	int* offsets;
	int offset_start;
	int filesize;
	char* tmpdata;
public:
	void ReadHeader(NtFileDisk& in, int file_size = -1);
	int CheckHeader(void); /* false: invalid true: valid */
	NWAData(void) {
		offsets = 0;
		tmpdata = 0;
	}
	~NWAData(void) {
		if (offsets) delete[] offsets;
		if (tmpdata) delete[] tmpdata;
	}
	int BlockLength(void) {
		if (complevel != -1) {
			if (offsets == 0) return false;
			if (tmpdata == 0) return false;
		}
		return blocksize * (bps / 8);
	}
	/* data �� BlockLength ���Ϥ��L����֤Ĥ���
	** ���ꂎ�����ɤ����ǩ`�����L�����K�˕r�� 0��
	** ����`�r�� -1
	*/
	int Decode(NtFileDisk& in, char* data, int& skip_count);
	void Rewind(NtFileDisk& in);
};

void NWAData::ReadHeader(NtFileDisk& in, int _file_size) {
	char header[0x2c];
	struct stat sb;
	int i;
	if (offsets) delete[] offsets;
	if (tmpdata) delete[] tmpdata;
	offsets = 0;
	tmpdata = 0;
	filesize = 0;
	offset_start = in.GetCurrentPos();
	if (offset_start == -1) offset_start = 0;
	if (_file_size != -1) filesize = _file_size;
	curblock = -1;
	/* header �i���z�� */
	in.Read(header, 0x2c);

	channels = read_little_endian_short(header + 0x00);
	bps = read_little_endian_short(header + 0x02);
	freq = read_little_endian_int(header + 0x04);
	complevel = read_little_endian_int(header + 0x08);
	use_runlength = read_little_endian_int(header + 0x0c);
	blocks = read_little_endian_int(header + 0x10);
	datasize = read_little_endian_int(header + 0x14);
	compdatasize = read_little_endian_int(header + 0x18);
	samplecount = read_little_endian_int(header + 0x1c);
	blocksize = read_little_endian_int(header + 0x20);
	restsize = read_little_endian_int(header + 0x24);
	dummy2 = read_little_endian_int(header + 0x28);
	if (complevel == -1) {	/* �o�R�sraw�ǩ`�� */
		/* �m���˛Q�������� */
		blocksize = 65536;
		restsize = (datasize % (blocksize * (bps / 8))) / (bps / 8);
		blocks = datasize / (blocksize * (bps / 8)) + (restsize > 0 ? 1 : 0);
	}
	if (blocks <= 0 || blocks > 1000000) {
		return;
	}
	/* regular file �ʤ� filesize �i���z�� */
	if (filesize == 0) {
		int pos = in.GetCurrentPos();
		filesize = in.GetSize32();
		if (pos + blocks * 4 >= filesize) {
			return;
		}
	}
	if (complevel == -1) return;
	/* offset index �i���z�� */
	offsets = new int[blocks];
	in.Read(offsets, blocks * 4);
	for (i = 0; i < blocks; i++) {
		offsets[i] = read_little_endian_int((char*)(offsets + i));
	}
}
void NWAData::Rewind(NtFileDisk& in) {
	curblock = -1;
	in.Seek(0x2c, FILE_BEGIN);
	if (offsets) in.Seek(blocks * 4, FILE_CURRENT);
}
int NWAData::CheckHeader(void)
{
	if (complevel != -1 && offsets == 0) return false;
	/* �ǩ`�����Τ�ΤΥ����å� */
	if (channels != 1 && channels != 2) {
		return false;
	}
	if (bps != 8 && bps != 16) {
		return false;
	}
	if (complevel == -1) {
		int byps = bps / 8; /* bytes per sample */
		if (datasize != samplecount*byps) {
			return false;
		}
		if (samplecount != (blocks - 1)*blocksize + restsize) {
			return false;
		}
		else
			return true;
	}
	if (complevel < 0 || complevel > 5) {
		return false;
	}
	/* �����ԥ����å� */
	if (filesize != 0 && filesize != compdatasize) {
		return false;
	}
	if (offsets[blocks - 1] >= compdatasize) {
		return false;
	}
	int byps = bps / 8; /* bytes per sample */
	if (datasize != samplecount*byps) {
		return false;
	}
	if (samplecount != (blocks - 1)*blocksize + restsize) {
		return false;
	}
	tmpdata = new char[blocksize*byps * 2]; /* �������Ϥδ󤭤��Ϥʤ����������� */
	return true;
}

class NWAInfo_sw2 {
public:
	int Channels(void) const{ return 2; }
	int Bps(void) const { return 16; }
	int CompLevel(void) const { return 2; }
	int UseRunLength(void) const { return false; }
};
int NWAData::Decode(NtFileDisk& in, char* data, int& skip_count) {
	if (complevel == -1) {		/* �o�R�s�r�΄I�� */
		if (curblock == -1) {
			/* ����Υ֥�å��ʤ顢wave header ���� */
			memcpy(data, make_wavheader(datasize, channels, bps, freq), 0x2c);
			curblock++;
			in.Seek(offset_start + 0x2c, FILE_BEGIN);
			return 0x2c;
		}
		if (skip_count > blocksize / channels) {
			skip_count -= blocksize / channels;
			in.Seek(blocksize*(bps / 8), FILE_CURRENT);
			curblock++;
			return -2;
		}
		if (curblock < blocks) {
			int readsize = blocksize;
			if (skip_count) {
				in.Seek(skip_count*channels*(bps / 8), FILE_CURRENT);
				readsize -= skip_count * channels;
				skip_count = 0;
			}
			LARGE_INTEGER err;
			err.QuadPart = 0;
			in.Read(data, readsize * (bps / 8), &err);
			curblock++;
			return err.LowPart;
		}
		return -1;
	}
	if (offsets == 0 || tmpdata == 0) return -1;
	if (blocks == curblock) return 0;
	if (curblock == -1) {
		/* ����Υ֥�å��ʤ顢wave header ���� */
		memcpy(data, make_wavheader(datasize, channels, bps, freq), 0x2c);
		curblock++;
		return 0x2c;
	}
	/* ����i���z�࣯�ǥ��`�ɤ���ǩ`���δ󤭤���ä� */
	int curblocksize, curcompsize;
	if (curblock != blocks - 1) {
		curblocksize = blocksize * (bps / 8);
		curcompsize = offsets[curblock + 1] - offsets[curblock];
		if (curblocksize >= blocksize*(bps / 8) * 2) return -1; // Fatal error
	}
	else {
		curblocksize = restsize * (bps / 8);
		curcompsize = blocksize*(bps / 8) * 2;
	}
	if (skip_count > blocksize / channels) {
		skip_count -= blocksize / channels;
		in.Seek(curcompsize, FILE_CURRENT);
		curblock++;
		return -2;
	}
	/* �ǩ`���i���z�� */
	in.Read(tmpdata, curcompsize);
	/* չ�_ */
	if (channels == 2 && bps == 16 && complevel == 2) {
		NWAInfo_sw2 info;
		NWADecode(info, tmpdata, data, curcompsize, curblocksize);
	}
	else {
		NWAInfo info(channels, bps, complevel, use_runlength);
		NWADecode(info, tmpdata, data, curcompsize, curblocksize);
	}
	int retsize = curblocksize;
	if (skip_count) {
		int skip_c = skip_count * channels * (bps / 8);
		retsize -= skip_c;
		memmove(data, data + skip_c, skip_c);
		skip_count = 0;
	}
	curblock++;
	return retsize;
}


void ConvertNwaToWav(NtFileDisk& in, StreamWriter& out, int skip_count, int in_size)
{
	NWAData h;
	h.ReadHeader(in, in_size);
	h.CheckHeader();
	int bs = h.BlockLength();
	char* d = new char[bs];
	int err;
	while ((err = h.Decode(in, d, skip_count)) != 0)
	{
		if (err == -1) break;
		if (err == -2) continue;
		out.Write(d, err);
	}
	return;
}
