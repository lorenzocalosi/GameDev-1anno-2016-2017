using UnityEngine;
using System;
using System.Collections;
using Random = UnityEngine.Random;
using UnityEngine.UI;

public class GameController : MonoBehaviour 
{
	public Base leftBase;
	public Base rightBase;

	public int startingMoney = 0;
	public int startingIncome = 20;

	public Text leftMoneyText;
	public Text rightMoneyText;

	private int leftCurrentMoney;
	private int rightCurrentMoney;

	public Text leftIncomeText;
	public Text rightIncomeText;

	private int leftCurrentIncome;
	private int rightCurrentIncome;

	public GameObject smallest;
	public GameObject small;
	public GameObject medium;
	public GameObject large;
	public GameObject largest;

	public float minDeployRange;
	public float maxDeployRange;

	public int incomeInterval;

	[HideInInspector]
	public bool isRunning = true;

	public Text gameOverText;

	private float nextIncome;

	// Use this for initialization
	void Start () 
	{
		gameOverText.text = "";

		leftCurrentMoney = startingMoney;
		rightCurrentMoney = startingMoney;

		leftCurrentIncome = startingIncome;
		rightCurrentIncome = startingIncome;

		leftMoneyText.text = leftCurrentMoney.ToString ();
		rightMoneyText.text = rightCurrentMoney.ToString ();

		leftIncomeText.text = leftCurrentIncome.ToString ();
		rightIncomeText.text = rightCurrentIncome.ToString ();
	}
	
	// Update is called once per frame
	void Update ()
	{
		Base currentBase = null;
		GameObject toBeInstatiated = null;

		if (Time.time > nextIncome)
		{
			nextIncome = Time.time + incomeInterval;
			incomeGain();
		}

		if(Input.GetKeyDown(KeyCode.Q))
		{
			toBeInstatiated = smallest;
			currentBase = leftBase;
		}
		else if(Input.GetKeyDown(KeyCode.W))
		{
			toBeInstatiated = small;
			currentBase = leftBase;
		}
		else if(Input.GetKeyDown(KeyCode.E))
		{
			toBeInstatiated = medium;
			currentBase = leftBase;
		}
		else if(Input.GetKeyDown(KeyCode.R))
		{
			toBeInstatiated = large;
			currentBase = leftBase;
		}
		else if(Input.GetKeyDown(KeyCode.T))
		{
			toBeInstatiated = largest;
			currentBase = leftBase;
		}
		else if(Input.GetKeyDown(KeyCode.Y))
		{
			toBeInstatiated = smallest;
			currentBase = rightBase;
		}
		else if(Input.GetKeyDown(KeyCode.U))
		{
			toBeInstatiated = small;
			currentBase = rightBase;
		}
		else if(Input.GetKeyDown(KeyCode.I))
		{
			toBeInstatiated = medium;
			currentBase = rightBase;
		}
		else if(Input.GetKeyDown(KeyCode.O))
		{
			toBeInstatiated = large;
			currentBase = rightBase;
		}
		else if(Input.GetKeyDown(KeyCode.P))
		{
			toBeInstatiated = largest;
			currentBase = rightBase;
		}

		if (toBeInstatiated != null && currentBase != null)
		{
			Vector3 position;
			Quaternion rotation;
			int priceToPay = toBeInstatiated.GetComponent<Fighter> ().price;
			int addedIncome = toBeInstatiated.GetComponent<Fighter> ().bonusIncome;
			if (currentBase == leftBase && leftCurrentMoney >= priceToPay)
			{
				position = new Vector3(currentBase.gameObject.transform.position.x + 2.0f, 0.0f, Random.Range(minDeployRange, maxDeployRange));
				rotation = Quaternion.Euler(new Vector3(0.0f, 90.0f, 0.0f));
				leftCurrentMoney -= priceToPay;
				leftCurrentIncome += addedIncome;
				updateMoneyHUD("left");
				updateIncomeHUD("left");
				GameObject fighter = Instantiate (toBeInstatiated, position, rotation) as GameObject;
				Fighter fighterScript = fighter.GetComponent<Fighter> ();
				fighterScript.owner = currentBase.owner;
				fighterScript.Unleash ();
			}
			else if (currentBase == rightBase && rightCurrentMoney >= priceToPay)
			{
				position = new Vector3(currentBase.gameObject.transform.position.x - 2.0f, 0.0f, Random.Range(minDeployRange, maxDeployRange));
				rotation = Quaternion.Euler(new Vector3(0.0f, -90.0f, 0.0f));
				rightCurrentMoney -= priceToPay;
				rightCurrentIncome += addedIncome;
				updateMoneyHUD("right");
				updateIncomeHUD("right");
				GameObject fighter = Instantiate (toBeInstatiated, position, rotation) as GameObject;
				Fighter fighterScript = fighter.GetComponent<Fighter> ();
				fighterScript.owner = currentBase.owner;
				fighterScript.Unleash ();
			}
		}
	}

	public void GameOver (Player loser)
	{
		isRunning = false;
		gameOverText.text = loser.name + "\nhas been destroyed!";
	}

	public void updateMoneyHUD(string selectedHUD)
	{
		if (selectedHUD == "left") 
		{
			leftMoneyText.text = leftCurrentMoney.ToString();
		}
		else
		{
			rightMoneyText.text = rightCurrentMoney.ToString();
		}
	}

	public void updateIncomeHUD(string selectedHUD)
	{
		if (selectedHUD == "left") 
		{
			leftIncomeText.text = leftCurrentIncome.ToString();
		}
		else
		{
			rightIncomeText.text = rightCurrentIncome.ToString();
		}
	}

	public void incomeGain()
	{
		leftCurrentMoney += leftCurrentIncome;
		updateMoneyHUD("left");
		rightCurrentMoney += rightCurrentIncome;
		updateMoneyHUD("right");
	}

	public void addMoney(int enemyPlayerIndex, int income)
	{
		if (enemyPlayerIndex == leftBase.owner.index) 
		{
			rightCurrentMoney += income;
			updateMoneyHUD ("right");
		} 
		else if (enemyPlayerIndex == rightBase.owner.index)
		{
			leftCurrentMoney += income;
			updateMoneyHUD ("left");
		}
	}
}
