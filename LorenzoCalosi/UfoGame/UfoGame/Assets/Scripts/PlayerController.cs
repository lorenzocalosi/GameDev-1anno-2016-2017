﻿using UnityEngine;
using System.Collections;

using UnityEngine.UI;

public class PlayerController : MonoBehaviour {

	public float speed;
	public Text countText;
	public Text winText;
	public int maxCount;

	private Rigidbody2D rb2d;
	private int count;
	private bool playerDead = false;

	// Use this for initialization
	void Start()
	{
		rb2d = GetComponent<Rigidbody2D> ();
		count = 0;
		winText.text = "";
		SetCountText();
	}

	//Update is called every deltaTime
	void FixedUpdate()
	{
		float moveHorizontal = Input.GetAxis ("Horizontal");
		float moveVertical = Input.GetAxis ("Vertical");
		Vector2 movement = new Vector2 (moveHorizontal, moveVertical);
		rb2d.AddForce (movement * speed);
	}
		
	void OnTriggerEnter2D(Collider2D other) 
	{
		if (other.gameObject.CompareTag ("PickUp")) {
			other.gameObject.SetActive (false);
			count = count + 1;
			SetCountText ();
		} else if (other.gameObject.CompareTag ("Enemy")) {
			playerDead = true;
			SetCountText ();
			this.gameObject.SetActive (false);
		}
		

	}

	void SetCountText()
	{
		countText.text = "Count: " + count.ToString ();
		if (count >= maxCount) {
			winText.text = "You win!";
		}
		if (playerDead) {
			winText.text = "You lose!";
		}
	}
}
