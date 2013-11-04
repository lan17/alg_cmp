#include <assert.h>
#include <stdio.h>

#define START 'K'
#define FIRST '('

static struct {
	char dot, dah;
} table[] =
	{ {0,  ')'},{0,  0  },{0,  0  },{0,  '.'},{0,  0  },{0,  0  },{0,  0  },{0,  0  }
	, {0,  0  },{'\'',0 },{0,  0  },{0,  0  },{0,  0  },{0,  0  },{0,  '-'},{0,  0  }
	, {':',0  },{0,  0  },{0,  0  },{0,  0  },{0,  0  },{0,  0  },{0,  0  },{0,  0  }
	, {0,  0  },{'B','2'},{'?','_'},{'+',0  },{'"',0  },{'@',0  },{';','!'},{0,  '('}
	, {0,  ','},{'8',0  },{'9','0'},{'e','t'},{0,  0  },{0,  0  },{0,  0  },{0,  0  }
	, {0,  0  },{0,  0  },{0,  0  },{0,  0  },{0,  0  },{0,  0  },{0,  0  },{0,  0  }
	, {0,  0  },{0,  0  },{0,  0  },{0,  0  },{0,  0  },{0,  0  },{0,  0  },{0,  0  }
	, {0,  0  },{'r','w'},{'6','='},{0,  'F'},{'b','x'},{'i','a'},{0,  0  },{'z','q'}
	, {'5','4'},{'s','u'},{0,  '1'},{'c','y'},{0,  'D'},{'g','o'},{'d','k'},{'I','J'}
	, {0,  'E'},{0,  0  },{'l','C'},{'h','v'},{'n','m'},{'f','A'},{0,  '3'},{'p','j'}
	, {'/',0  },{'G',0  },{'7','H'},{0,  0  },{0,  0  },{0,  0  },{0,  0  },{0,  0  } };

#define D(c)  (table[(int)(c - FIRST)])
#define DO(c) (D(c).dot)
#define DA(c) (D(c).dah)

void decode(const char *str) {
	char at = START;
	while(*str){
		if (*str == '.') at = DO(at);
		else if (*str == '-') at = DA(at);
		else {
			if (at != START) putchar(at);
			at = START;
		};
		++str;
	};
	if (at != START) putchar(at);
	putchar('\n');
}

int main(int argc, char *argv[]) {
	assert(argc==2);
	decode(argv[1]);
	return 0;
}
