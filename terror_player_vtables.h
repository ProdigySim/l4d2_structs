#ifndef _INCLUDE_TERROR_PLAYER_VTABLES_H_
#define _INCLUDE_TERROR_PLAYER_VTABLES_H_

#include "network_var.h"
#include "handle.h"

// sizeof(IServerUnknown_iface) == 12
struct IServerUnknown_iface
{
	void * GetCollideable; // 0
	void * GetNetworkable; // 4
	void * GetBaseEntity; // 8
};

// sizeof(IServerEntity_iface) == 12
struct IServerEntity_iface
{
	void * GetModelIndex; // 0
	void * GetModelName; // 4
	void * SetModelIndex; // 8
};

// sizeof(CBaseEntity_iface) == 760
struct CBaseEntity_iface
{
	void * GetServerClass; // 0
	void * YouForgotToImplementOrDeclareServerClass; // 4
	void * GetDataDescMap; // 8
	void * GetScriptDesc; // 12
	void * GetAIAddOn; // 16
	void * TestCollision; // 20
	void * TestHitboxes; // 24
	void * ComputeWorldSpaceSurroundingBox; // 28
	void * ShouldCollide; // 32
	void * SetOwnerEntity; // 36
	void * ShouldTransmit; // 40
	void * UpdateTransmitState; // 44
	void * SetTransmit; // 48
	void * GetTracerType; // 52
	void * Spawn; // 56
	void * ShouldPrecache; // 60
	void * Precache; // 64
	void * SetModel; // 68
	void * InitSharedVars; // 72
	void * PostConstructor; // 76
	void * PostClientActive; // 80
	void * OnParseMapDataFinished; // 84
	void * KeyValue; // 88
	void * KeyValue2; // 92
	void * KeyValue3; // 96
	void * GetKeyValue; // 100
	void * Activate; // 104
	void * SetParent; // 108
	void * SetStasis; // 112
	void * IsInStasis; // 116
	void * ObjectCaps; // 120
	void * GetUsePriority; // 124
	void * GetGlowEntity; // 128
	void * GetUseType; // 132
	void * AcceptInput; // 136
	void * GetPlayerName; // 140
	void * DrawDebugGeometryOverlays; // 144
	void * DrawDebugTextOverlays; // 148
	void * Save; // 152
	void * Restore; // 156
	void * ShouldSavePhysics; // 160
	void * OnSave; // 164
	void * OnRestore; // 168
	void * GetDemoRecordingState; // 172
	void * RequiredEdictIndex; // 176
	void * MoveDone; // 180
	void * Think; // 184
	NetworkVar_iface m_nNextThinkTick; // 188
	void * GetBaseAnimating; // 196
	void * GetBaseAnimatingOverlay; // 200
	void * GetResponseSystem; // 204
	void * DispatchResponse; // 208
	void * Classify; // 212
	void * DeathNotice; // 216
	void * ShouldAttractAutoAim; // 220
	void * GetAutoAimRadius; // 224
	void * GetAutoAimCenter; // 228
	void * GetBeamTraceFilter; // 232
	void * PassesDamageFilter; // 236
	void * TraceAttack; // 240
	void * CanBeHitByMeleeAttack; // 244
	void * OnTakeDamage; // 248
	void * TakeHealth; // 252
	void * IsAlive; // 256
	void * Event_Killed; // 260
	void * Event_KilledOther; // 264
	void * BloodColor; // 268
	void * IsTriggered; // 272
	void * IsNPC; // 276
	void * MyCombatCharacterPointer; // 280
	void * MyNextBotPointer; // 284
	void * MyInfectedPointer; // 288
	void * GetDelay; // 292
	void * IsMoving; // 296
	void * DamageDecal; // 300
	void * DecalTrace; // 304
	void * ImpactTrace; // 308
	void * OnControls; // 312
	void * HasTarget; // 316
	void * IsPlayer; // 320
	void * IsNetClient; // 324
	void * IsTemplate; // 328
	void * IsBaseObject; // 332
	void * IsBaseTrain; // 336
	void * IsElevator; // 340
	void * IsBaseCombatWeapon; // 344
	void * MyCombatWeaponPointer; // 348
	void * GetServerVehicle; // 352
	void * IsViewable; // 356
	void * ChangeTeam; // 360
	void * OnEntityEvent; // 364
	void * CanStandOn; // 368
	void * CanStandOn2; // 372
	void * GetEnemy; // 376
	void * GetEnemy2; // 380
	void * Use; // 384
	void * StartTouch; // 388
	void * Touch; // 392
	void * EndTouch; // 396
	void * StartBlocked; // 400
	void * Blocked; // 404
	void * EndBlocked; // 408
	void * PhysicsSimulate; // 412
	void * PhysicsLandedOnGround; // 416
	void * UpdateOnRemove; // 420
	void * StopLoopingSounds; // 424
	void * SUB_AllowedToFade; // 428
	void * Teleport; // 432
	void * NotifySystemEvent; // 436
	void * MakeTracer; // 440
	void * GetTracerAttachment; // 444
	void * FireBullets; // 448
	void * DoImpactEffect; // 452
	void * Respawn; // 456
	void * IsLockedByMaster; // 460
	void * GetMaxHealth; // 464
	void * ModifyOrAppendCriteria; // 468
	void * ModifyOrAppendDerivedCriteria; // 472
	NetworkVar_iface m_iMaxHealth; // 476
	NetworkVar_iface m_iHealth; // 484
	NetworkVar_iface m_lifeState; // 492
	NetworkVar_iface m_takedamage; // 500
	void * GetDamageType; // 508
	void * GetDamage; // 512
	void * SetDamage; // 516
	void * EyePosition; // 520
	void * EyeAngles; // 524
	void * LocalEyeAngles; // 528
	void * EarPosition; // 532
	void * BodyTarget; // 536
	void * HeadTarget; // 540
	void * GetVectors; // 544
	void * GetViewOffset; // 548
	void * SetViewOffset; // 552
	void * GetSmoothedVelocity; // 556
	void * GetVelocity; // 560
	void * GetFriction; // 564
	void * FVisible; // 568
	void * FVisible2; // 572
	void * CanBeSeenBy; // 576
	void * GetAttackDamageScale; // 580
	void * GetReceivedDamageScale; // 584
	void * OnGroundChanged; // 588
	void * GetGroundVelocityToApply; // 592
	void * PhysicsSplash; // 596
	void * Splash; // 600
	void * WorldSpaceCenter; // 604
	void * GetSoundEmissionOrigin; // 608
	void * CreateVPhysics; // 612
	void * ForceVPhysicsCollide; // 616
	void * VPhysicsDestroyObject; // 620
	void * VPhysicsUpdate; // 624
	void * VPhysicsTakeDamage; // 628
	void * VPhysicsShadowCollision; // 632
	void * VPhysicsShadowUpdate; // 636
	void * VPhysicsCollision; // 640
	void * VPhysicsFriction; // 644
	void * UpdatePhysicsShadowToCurrentPosition; // 648
	void * VPhysicsGetObjectList; // 652
	void * VPhysicsIsFlesh; // 656
	void * CanPushEntity; // 660
	void * HasPhysicsAttacker; // 664
	void * PhysicsSolidMaskForEntity; // 668
	void * ResolveFlyCollisionCustom; // 672
	void * PerformCustomPhysics; // 676
	void * GetStepOrigin; // 680
	void * GetStepAngles; // 684
	void * ShouldDrawWaterImpacts; // 688
	NetworkVar_iface m_fFlags; // 692
	NetworkVar_iface m_nWaterLevel; // 700
	NetworkVar_iface m_hGroundEntity; // 708
	NetworkVar_iface m_vecBaseVelocity; // 716
	NetworkVar_iface m_flFriction; // 724
	NetworkVar_iface m_vecVelocity; // 732
	NetworkVar_iface m_bClientSideRagdoll; // 740
	NetworkVar_iface m_vecViewOffset; // 748
	void * RunVScripts; // 756
};

// sizeof(CBaseAnimating_iface) == 124
struct CBaseAnimating_iface
{
	void * GetIdealSpeed; // 200 
	void * GetIdealAccel;
	void * StudioFrameAdvance;
	void * ReachedEndOfSequence;
	void * OnSequenceSet;
	void * IsActivityFinished;
	void * GetSequenceGroundSpeed;
	void * SelectWeightedSequence;  // 207
	void * ClampRagdollForce;
	void * BecomeRagdollOnClient;
	void * IsRagdoll;
	void * CanBecomeRagdoll;
	void * GetSkeleton;
	void * GetBoneTransform;
	void * SetupBones;
	void * CalculateIKLocks;
	void * DispatchAnimEvents;
	void * HandleAnimEvent;
	void * PopulatePoseParameters;
	void * GetAttachment;
	void * InitBoneControllers;
	void * GetGroundSpeedVelocity;
	void * IsViewModel;
	void * Ignite;
	void * IgniteLifetime;
	void * IgniteUseCheapEffect;
	void * Extinguish;
	void * IsFrozen;
	void * Freeze;
	void * Unfreeze;
	void * Dissolve;
	void * SetLightingOrigin;
};

// sizeof(CBaseFlex_iface) == 32
struct CBaseFlex_iface
{
	void * SetViewtarget; // 0
	void * StartSceneEvent; // 4
	void * ProcessSceneEvents; // 8
	void * ProcessSceneEvent; // 12
	void * ClearSceneEvent; // 16
	void * CheckSceneEventCompletion; // 20
	void * PlayScene; // 24
	void * PlayAutoGeneratedSoundScene; // 28
};

// sizeof(CBaseCombatCharacter_iface) == 416
struct CBaseCombatCharacter_iface
{
	void * GetPhysicsImpactDamageTable;
	void * FInViewCone;
	void * FInViewCone2;
	void * FInAimCone;
	void * FInAimCone2;
	void * ShouldShootMissTarget;
	void * FindMissTarget;
	void * HandleInteraction;
	void * BodyAngles;
	void * BodyDirection2D;
	void * BodyDirection3D2;
	void * HeadDirection2D;
	void * HeadDirection3D2;
	void * EyeDirection2D;
	void * EyeDirection3D2;
	void * IsHiddenByFog;
	void * IsHiddenByFog2;
	void * IsHiddenByFog3;
	void * GetFogObscuredRatio;
	void * GetFogObscuredRatio2;
	void * GetFogObscuredRatio3;
	void * GetFogParams;
	void * IsLookingTowards;
	void * IsLookingTowards2;
	void * IsInFieldOfView;
	void * IsInFieldOfView2;
	void * IsLineOfSightClear;
	void * IsLineOfSightClear2;
	void * OnFootstep;
	void * GetGroundSurface;
	void * GetFootstepSound;
	void * AreFootstepsAudible;
	void * IsFootstepAudible;
	void * GetFootstepRunThreshold;
	void * GiveAmmo;
	void * RemoveAmmo;
	void * NPC_TranslateActivity;
	void * Weapon_TranslateActivity;
	void * Weapon_FrameUpdate;
	void * Weapon_HandleAnimEvent;
	void * Weapon_CanUse;
	void * Weapon_Equip;
	void * Weapon_EquipAmmoOnly;
	void * Weapon_Drop;
	void * Weapon_Switch;
	void * Weapon_ShootPosition;
	void * Weapon_CanSwitchTo;
	void * Weapon_SlotOccupied;
	void * Weapon_GetSlot;
	void * AddPlayerItem;
	void * RemovePlayerItem;
	void * CanBecomeServerRagdoll;
	void * OnTakeDamage_Alive;
	void * OnTakeDamage_Dying;
	void * OnTakeDamage_Dead;
	void * GetAliveDuration;
	void * OnFriendDamaged;
	void * NotifyFriendsOfDamage;
	void * HasEverBeenInjured;
	void * GetTimeSinceLastInjury;
	void * OnPlayerKilledOther;
	void * GetDeathActivity;
	void * CorpseGib;
	void * CorpseFade;
	void * HasHumanGibs;
	void * HasAlienGibs;
	void * ShouldGib;
	void * OnKilledNPC;
	void * Event_Gibbed;
	void * Event_Dying;
	void * BecomeRagdoll;
	void * FixupBurningServerRagdoll;
	void * BecomeRagdollBoogie;
	void * CheckTraceHullAttack;
	void * CheckTraceHullAttack2;
	void * PushawayTouch;
	void * IRelationType;
	void * IRelationPriority;
	void * IsInAVehicle;
	void * GetVehicle;
	void * GetVehicleEntity;
	void * ExitVehicle;
	void * CalcWeaponProficiency;
	void * GetAttackSpread;
	void * GetSpreadBias;
	void * DoMuzzleFlash;
	void * AddEntityRelationship;
	void * RemoveEntityRelationship;
	void * AddClassRelationship;
	void * OnChangeActiveWeapon;
	void * GetLastKnownArea;
	void * IsAreaTraversable;
	void * ClearLastKnownArea;
	void * UpdateLastKnownArea;
	void * OnNavAreaChanged;
	void * OnNavAreaRemoved;
	void * GetClass;
	void * CanBeA;
	void * OnHitByVomitJar;
	void * IsIT;
	void * OnPursuedBy;
	void * IsGhost;
	NetworkVar_iface m_iAmmo;
};

// sizeof(CBasePlayer_iface) == 576
struct CBasePlayer_iface
{
	void * CreateViewModel;
	void * SetupVisibility;
	void * WantsLagCompensationOnEntity;
	void * SharedSpawn;
	void * ForceRespawn;
	void * InitialSpawn;
	void * InitHUD;
	void * ShowViewPortPanel;
	void * PlayerDeathThink;
	void * Jump;
	void * Duck;
	void * Cough;
	void * PreThink;
	void * PostThink;
	void * DamageEffect;
	void * OnDamagedByExplosion;
	void * ShouldFadeOnDeath;
	void * IsFakeClient;
	void * GetCharacterDisplayName;
	void * GetPlayerMins;
	void * GetPlayerMaxs;
	void * UpdateCollisionBounds;
	void * CalcRoll;
	void * PackDeadPlayerItems;
	void * RemoveAllItems;
	void * IsRunning;
	void * Weapon_SetLast;
	void * Weapon_ShouldSetLast;
	void * Weapon_ShouldSelectItem;
	void * HasUnlockableWeapons;
	void * UpdateClientData;
	void * UpdateBattery;
	void * ExitLadder;
	void * GetLadderSurface;
	void * IsAbleToAutoCenterOnLadders;
	void * SetFlashlightEnabled;
	void * FlashlightIsOn;
	void * FlashlightTurnOn;
	void * FlashlightTurnOff;
	void * IsIlluminatedByFlashlight;
	void * UpdateStepSound;
	void * PlayStepSound;
	void * GetStepSoundVelocities;
	void * SetStepSoundTime;
	void * DeathSound;
	void * GetSoundscapeListener;
	void * WeaponHasInfiniteAmmo;
	void * SetAnimation;
	void * OnMainActivityComplete;
	void * OnMainActivityInterrupted;
	void * ImpulseCommands;
	void * CheatImpulseCommands;
	void * ClientCommand;
	void * StartObserverMode;
	void * StopObserverMode;
	void * ModeWantsSpectatorGUI;
	void * SetObserverMode;
	void * GetObserverMode;
	void * SetObserverTarget;
	void * ObserverUse;
	void * GetObserverTarget;
	void * FindNextObserverTarget;
	void * GetNextObserverSearchStartPoint;
	void * PassesObserverFilter;
	void * IsValidObserverTarget;
	void * CheckObserverSettings;
	void * JumptoPosition;
	void * ForceObserverMode;
	void * ResetObserverMode;
	void * ValidateCurrentObserverTarget;
	void * AttemptToExitFreezeCam;
	void * WantsRoamingObserverMode;
	void * StartReplayMode;
	void * StopReplayMode;
	void * GetDelayTicks;
	void * GetReplayEntity;
	void * CreateCorpse;
	void * EntSelectSpawnPoint;
	void * GetInVehicle;
	void * LeaveVehicle;
	void * OnVehicleStart;
	void * OnVehicleEnd;
	void * BumpWeapon;
	void * SelectLastItem;
	void * SelectItem;
	void * SelectItem2;
	void * ItemPostFrame;
	void * GiveNamedItem;
	void * CheckTrainUpdate;
	void * SetPlayerUnderwater;
	void * PlayWadeSound;
	void * CanBreatheUnderwater;
	void * CanRecoverCurrentDrowningDamage;
	void * PlayerUse;
	void * PlayUseDenySound;
	void * FindUseEntity;
	void * IsUseableEntity;
	void * OnUseEntity;
	void * PickupObject;
	void * ForceDropOfCarriedPhysObjects;
	void * GetHeldObjectMass;
	void * IsHoldingEntity;
	void * UpdateGeigerCounter;
	void * GetAutoaimVector;
	void * GetAutoaimVector2;
	void * GetAutoaimVector3;
	void * GetAutoaimVector4;
	void * ShouldAutoaim;
	void * ForceClientDllUpdate;
	void * ProcessUsercmds;
	void * PlayerRunCommand;
	void * ChangeTeam;
	void * CanHearAndReadChatFrom;
	void * CanSpeak;
	void * ModifyOrAppendPlayerCriteria;
	void * CheckChatText;
	void * CreateRagdollEntity;
	void * ShouldAnnounceAchievement;
	void * ForceChangeTeam;
	void * IsFollowingPhysics;
	void * InitVCollision;
	void * UpdatePhysicsShadowToCurrentPosition;
	void * Hints;
	void * IsReadyToPlay;
	void * IsReadyToSpawn;
	void * ShouldGainInstantSpawn;
	void * ResetPerRoundStats;
	void * ResetScores;
	void * EquipSuit;
	void * RemoveSuit;
	void * OnUseEntityChanged;
	void * CommitSuicide;
	void * CommitSuicide2;
	void * IsBot;
	void * GetExpresser;
	void * SpawnArmorValue;
	void * UpdateTonemapController;
	NetworkVar_iface m_ArmorValue;
	void * IsAutoCrouched;
	void * GetAvailableSteadyStateSlots;
	void * OnSpeak;
	void * OnVoiceTransmit;
	void * PlayerSolidMask;
};

// CAI_ExpressorHost<CBasePlayer>
// sizeof(CAI_ExpresserHost_CBasePlayer__iface) == 16
struct CAI_ExpresserHost_CBasePlayer__iface
{
	void * NoteSpreaking; // 0
	void * Speak; // 4
	void * Speak2; // 8
	void * PostSpeakDispatchResponse; // 12
};

// sizeof(CBaseMultiplayerPlayer_iface) == 36
struct CBaseMultiplayerPlayer_iface
{
	void * SpeakIfAllowed; // 0
	void * SpeakConceptIfAllowed; // 4
	void * CanSpeakVoiceCommand; // 8
	void * ShouldShowVoiceSubtitleToEnemy; // 12
	void * NoteSpokeVoiceCommand; // 16
	void * OnAchievementEarned; // 20
	void * GetMultiplayerExpresser; // 24
	void * CalculateTeamBalanceScore; // 28
	void * CreateExpresser; // 32
};

// sizeof(CCSPlayer_iface) == 224
struct CCSPlayer_iface
{
	void * FirePlayerHurtEvent; // 0
	void * OnTakeDamageInternal; // 4
	void * AllowDamage; // 8
	void * GetHealthBuffer; // 12
	void * IsIncapacitated; // 16
	void * GetAdjustedDamage; // 20
	void * DoBloodEffect; // 24
	void * GiveNamedItem; // 28
	void * IsBeingGivenItem; // 32
	void * DoAnimationEvent; // 36
	void * KickBack; // 40
	void * IsImmobilized; // 44
	void * GiveDefaultItems; // 48
	void * RoundRespawn; // 52
	void * ObserverRoundRespawn; // 56
	void * Blind; // 60
	void * Deafen; // 64
	void * ResetMaxSpeed; // 68
	void * HandleCommand_JoinClass; // 72
	void * HandleCommand_JoinTeam; // 76
	void * GetIntoGame; // 80
	void * WantsMOTD; // 84
	void * AutoSelectTeam; // 88
	void * OnLeaveActiveState; // 92
	void * Pain; // 96
	void * OnTeamChanged; // 100
	void * CanAttack; // 104
	void * OnWeaponFired; // 108
	void * QueueScreenBloodSplatter; // 112
	void * OnReloadStart; // 116
	void * CreateNoise; // 120
	void * OnPreThinkObserverMode; // 124
	void * OnEnterRescueState; // 128
	void * OnPreThinkRescueState; // 132
	void * OnLeaveRescueState; // 136
	void * OnEnterGhostState; // 140
	void * OnPreThinkGhostState; // 144
	void * OnLeaveGhostState; // 148
	void * OnEnterIntroCameraState; // 152
	void * OnPreThinkIntroCameraState; // 156
	void * OnLeaveIntroCameraState; // 160
	void * OnLeaveDeathAnimState; // 164
	void * OnLeaveDeathWaitForKeyState; // 168
	void * CanUseFlashlight; // 172
	void * UpdateAddonBits; // 176
	void * UpdateRadar; // 180
	void * SelectDeathPose; // 184
	void * CanChangeName; // 188
	void * ChangeName; // 192
	void * IsProgressBarActive; // 196
	void * CreateRagdollEntity; // 200
	void * GetRagdollType; // 204
	void * SetModelFromClass; // 208
	void * SetModelFromClassAtSpawn; // 212
	void * DropWeapons; // 216
	void * RecordDamageTaken; // 220
};

// sizeof(CTerrorPlayer_iface) == 124
struct CTerrorPlayer_iface
{
	void * OnPlayerDisconnected; // 0
	void * OnSpawn; // 4
	void * RestoreSpawn; // 8
	void * OnBeginChangeLevel; // 12
	void * OnEndChangeLevel; // 16
	void * HandleCommand_JoinTeam; // 20
	void * SetDoingRestore; // 24
	void * GetTeamSwitchRule; // 28
	void * IsReadyToShove; // 32
	void * SetNextShoveTime; // 36
	void * CommitSuicide; // 40
	void * OnSpokeConcept; // 44
	void * RestoreWeapons; // 48
	void * DropWeaponInSlot; // 52
	void * QueueScreenBloodSplatter; // 56
	void * OnReloadEnd; // 60
	void * OnReloadAbort; // 64
	void * OnAttackSuccess; // 68
	void * CanBeShoved; // 72
	void * IsWielding; // 76
	void * IsWieldingWeaponOfType; // 80
	void * IsZoomed; // 84
	void * CanPlayerJump; // 88
	void * PlayerZombieAbortControl; // 92
	void * CanBeShoved; // 96
	void * SetClass; // 100
	void * SetCharacter; // 104
	void * OnRevived; // 108
	void * OnAwardEarned; // 112
	void * OnAwardLost; // 116
	void * ScoreKilledZombie; // 120
};

struct CBaseEntity_vtable
{
	void * dtor1; // 0
	void * dtor0; // 4
	IHandleEntity_iface IHandleEntity; // 8
	IServerUnknown_iface IServerUnknown; // 16
	IServerEntity_iface IServerEntity; // 28
	CBaseEntity_iface CBaseEntity; // 40
};


struct CBaseFlex_vtable
{
	void * dtor1; // 0
	void * dtor0; // 4
	IHandleEntity_iface IHandleEntity; // 8
	IServerUnknown_iface IServerUnknown; // 16
	IServerEntity_iface IServerEntity; // 28
	CBaseEntity_iface CBaseEntity; // 40
	CBaseAnimating_iface CBaseAnimating; // 800
	CBaseFlex_iface CBaseFlex; // 924
};

struct CBaseCombatCharacter_vtable
{
	void * dtor1; // 0
	void * dtor0; // 4
	IHandleEntity_iface IHandleEntity; // 8
	IServerUnknown_iface IServerUnknown; // 16
	IServerEntity_iface IServerEntity; // 28
	CBaseEntity_iface CBaseEntity; // 40
	CBaseAnimating_iface CBaseAnimating; // 800
	CBaseFlex_iface CBaseFlex; // 924
	CBaseCombatCharacter_iface CBaseCombatCharacter; // 956
};

struct CTerrorPlayer_vtable
{
	void * dtor1; // 0
	void * dtor0; // 4
	IHandleEntity_iface IHandleEntity; // 8
	IServerUnknown_iface IServerUnknown; // 16
	IServerEntity_iface IServerEntity; // 28
	CBaseEntity_iface CBaseEntity; // 40
	CBaseAnimating_iface CBaseAnimating; // 800
	CBaseFlex_iface CBaseFlex; // 924
	CBaseCombatCharacter_iface CBaseCombatCharacter; // 956
	CBasePlayer_iface CBasePlayer; // 1372
	CAI_ExpresserHost_CBasePlayer__iface CAI_ExpresserHost; // 1948
	CBaseMultiplayerPlayer_iface CBaseMultiplayerPlayer; // 1964
	CCSPlayer_iface CCSPlayer; // 2000
	CTerrorPlayer_iface CTerrorPlayer; // 2224
};

struct CAI_ExpresserSink_vtable
{
	void * OnSpokeConcept; // 0
	void * OnStartSpeaking; // 4
	void * UseSemaphore; // 8
};

#endif // _INCLUDE_TERROR_PLAYER_VTABLES_H_