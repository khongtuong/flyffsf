/*/////////////////////////////////////////////////////////////////////////////////////////////////////////////////

������) ����ġ �ٿ�, HPȸ����ġ�� % �� ��� �Ҽ����� ǥ���ϱ� ���� ���ϱ� 100�� ������ ����˴ϴ�.

REVIVAL_PENALTY		// ��Ȱ Penalty
{
����)	ADDPENALTY	����	HPȸ����ġ(%)
��) 	ADDPENALTY	1	8000
	ADDPENALTY	2	6000
	ADDPENALTY	5	5000
	// 0~1������ ��Ȱ�ϸ� MAX HP�� 80%�� HP�� ȸ����
	// 2~2������ ��Ȱ�ϸ� MAX HP�� 60%�� HP�� ȸ����
	// 3~5������ ��Ȱ�ϸ� MAX HP�� 50%�� HP�� ȸ����
}

DECEXP_PENALTY
{
����)	ADDPENALTY	����	����ġ�ٿ�(%)
��) 	ADDPENALTY	20	0
	ADDPENALTY	29	60		
	// 0~20������ ������ 0%�� ����ġ�� ����
	// 21~29������ ������ 6%�� ����ġ�� ����
}

LEVEL_DOWN_PENALTY
{
����)	ADDPENALTY	����	�����ٿ�(��/��)
��) 	ADDPENALTY	20	0
	ADDPENALTY	200	1	
	// 0~20���� �׾����� �����ٿ��� �Ҽ� ����
	// 21~200���� �׾����� �����ٿ��� �Ҽ� ����
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////*/

REVIVAL_PENALTY
{
	ADDPENALTY	1	8000
	ADDPENALTY	2	6000
	ADDPENALTY	5	5000
	ADDPENALTY	10	4000
	ADDPENALTY	200	3000
}

DECEXP_PENALTY
{
	ADDPENALTY	20	0
	ADDPENALTY	29	600
	ADDPENALTY	59	500
	ADDPENALTY	89	400
	ADDPENALTY	99	300
	ADDPENALTY	109	200
	ADDPENALTY	129	150
	ADDPENALTY	200	100
}

LEVEL_DOWN_PENALTY
{
	ADDPENALTY	20	0
	ADDPENALTY	200	1
}