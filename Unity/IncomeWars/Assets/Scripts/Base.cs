using UnityEngine;
using System.Collections;
using UnityEngine.UI;

public class Base : Target
{
	public Player editorOwner;

	public Text hpText;

	// Use this for initialization
	void Start () 
	{ 
		owner = editorOwner;
		UpdateHealthHUD();
	}

	void UpdateHealthHUD()
	{
		hpText.text = currentHP.ToString();
	}

	protected override void Loss(int loss)
	{
		base.Loss(loss);
		UpdateHealthHUD();
	}

	void OnDestroy()
	{
		gameController.GameOver(owner);
	}
}
