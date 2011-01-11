// 1.0�� �⺻ ��
// 2.0�� ���
// 0.5�� 1/2

// itemDropRate = 1.0 // ������ ��ӷ� 
// goldDropRate = 1.0 // ��� ��ӷ�
// monsterExpRate = 1.0 // ���� ����ġ�� 
// monsterHitRate = 1.0 // ���� ��Ʈ�� (������ ���ݷ�)

// ������ ��ġ ; resource\constant.inc
// Constant.txt�� ���� ������ ��ũ��Ʈ�̸� ���� ������ �Ŀ� �ݵ�� ���� ������ �����ؾ��Ѵ�.

// ��� ���ɾ� ; ���� ��ġ�� ���ӳ������� �ǽð� ���� ������. ������ �Է����� �ʰ� �׳� ����ġ�� ���� ���� ���

// ���� ����
// ItemDropRade   [����]
// GoldDropRade   [����]
// MonsterExpRate [����]
// MonsterHitRate [����]

// �ѱ� ����
// �����۵�ӷ�   [����]
// ����ӷ�     [����]
// ���Ͱ���ġ�� [����]
// ������Ʈ��   [����]

//----------------------------------------------------------------------------------------------------// 
lang LANG_KOR // ��� ����, ���� �ѱ� ������ ����
{
  formula 
  {
    itemDropRate = 1.0 
    goldDropRate = 1.0 
    monsterExpRate = 1.0 
    monsterHitRate = 1.0
    dwVagSP = 1
    dwExpertSP = 2
    dwProSP = 3
  }
}
//----------------------------------------------------------------------------------------------------// 
lang LANG_JAP // �Ϻ� ���̵� ����.(�Ϻ� �����ڵ��� �̺κи� ��ġ�ð�, ���� ��ġ�� �ѱ� �������� overwrite�� �� �����Ƿ� �Ƚ��� ��ġ�� �ѱ��� �뺸 �ٶ�)
{
  formula 
  {
    itemDropRate = 1.0 // ������ ��ӷ� 1.0�̸� �⺻��, 2.0�̸� �ι�, 3.0�̸� ����. ���� ��� ���� ��Ģ. ���� ���� ����� ���
    goldDropRate = 1.0 // ��� ��ӷ� ; ���� ���� ��� ��ӷ� ���
    monsterExpRate = 1.0 // ���� ����ġ�� ; ���� ���� ���Ͱ� �ִ� ����ġ ���
    monsterHitRate = 1.0 // ���� ��Ʈ�� (������ ���ݷ�) ���� ���� ������ ���ݷ��� ������.
  }
}
//----------------------------------------------------------------------------------------------------// 
lang LANG_CHI // ��� ����, ���� �ѱ� ������ ����
{
  formula 
  {
    itemDropRate = 1.0 
    goldDropRate = 1.0 
    monsterExpRate = 0.9 
    monsterHitRate = 1.0
  }
  test
  {
    itemDropRate = 1.0 
    goldDropRate = 1.0 
    monsterExpRate = 0.9 
    monsterHitRate = 1.0
  }
}

lang LANG_CHI // ��� ����, ���� �ѱ� ������ ����
{
  formula 
  {
    itemDropRate = 1.0 
    goldDropRate = 1.0 
    monsterExpRate = 0.9 
    monsterHitRate = 1.0
  }
  test
  {
    itemDropRate = 1.0 
    goldDropRate = 1.0 
    monsterExpRate = 0.9 
    monsterHitRate = 1.0
  }
}

lang LANG_ENG// ��� ����, ���� �ѱ� ������ ����
{
  formula 
  {
    itemDropRate = 1.0 
    goldDropRate = 1.0 
    monsterExpRate = 1.0 
    monsterHitRate = 1.0
  }
  test
  {
    itemDropRate = 1.0 
    goldDropRate = 1.0 
    monsterExpRate = 1.0 
    monsterHitRate = 1.0
  }
}