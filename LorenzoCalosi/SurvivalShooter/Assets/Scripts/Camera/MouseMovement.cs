﻿using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class MouseMovement : MonoBehaviour {

	public float speedH = 2.0f;
	public float speedV = 2.0f;

	public Transform mainPlayer;

	private float yaw = 0.0f;
	private float pitch = 0.0f;

	void Update () {
		yaw += speedH * Input.GetAxis("Mouse X");
		pitch -= speedV * Input.GetAxis("Mouse Y");

		transform.eulerAngles = new Vector3(pitch, yaw, 0.0f);
		mainPlayer.eulerAngles = new Vector3 (pitch, yaw, 0.0f);
	}
}